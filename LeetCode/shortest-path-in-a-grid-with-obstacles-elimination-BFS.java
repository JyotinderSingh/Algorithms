
// https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;


// BFS
class Solution {
  class StepState {
    /**
     * You must override hashCode() in every class that overrides equals().
     * Failure to do so will result in a violation of the general contract for
     * Object.hashCode(), which will prevent your class from functioning
     * properly in conjunction with all hash-based collections, including
     * HashMap, HashSet, and Hashtable.
     */
    int row;
    int col;
    int steps;
    int k;

    public StepState(int steps, int row, int col, int k) {
      this.steps = steps;
      this.row = row;
      this.col = col;
      this.k = k;
    }

    /**
     * Needed when we want to use the StepState as a key in a container like
     * HashMap.
     */
    @Override
    public int hashCode() {
      return (this.row + 1) * (this.col + 1) + this.k;
    }

    /**
     * Override equals to make sure we can compare StepState objects.
     *
     * @param other The object to compare to.
     * @return True if the objects are equal. False otherwise.
     */
    @Override
    public boolean equals(Object other) {
      if (!(other instanceof StepState)) {
        return false;
      }

      StepState stepState = (StepState) other;
      // We need to check if the row and col are the same, and if the k is the
      // same.
      return this.row == stepState.row && this.col == stepState.col &&
          this.k == stepState.k;
    }

    @Override
    public String toString() {
      return String.format("(%d, %d, %d)", this.row, this.col, this.k);
    }
  }

  public int shortestPath(int[][] grid, int k) {
    int rows = grid.length, cols = grid[0].length;
    int[] target = new int[] { rows - 1, cols - 1 };
    int[][] dirs = new int[][] { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

    // If we have sufficient quota to eliminate obstacles in worst case on the
    // shortest path, then we can just return the number of steps - which
    // would be equal to the Manhattan distance between the start and target.
    if (k >= rows + cols - 2) {
      return rows + cols - 2;
    }

    Queue<StepState> queue = new LinkedList<>();
    HashSet<StepState> seen = new HashSet<>();

    // Add the start state to the queue.
    StepState start = new StepState(0, 0, 0, k);
    queue.offer(start);
    seen.add(start);

    while (!queue.isEmpty()) {
      StepState curr = queue.poll();

      // Check if we are at target
      if (curr.row == target[0] && curr.col == target[1]) {
        return curr.steps;
      }

      for (int[] dir : dirs) {
        int nextRow = curr.row + dir[0];
        int nextCol = curr.col + dir[1];

        // Check if we are out of bounds
        if (nextRow < 0 || nextRow >= rows || nextCol < 0 || nextCol >= cols) {
          continue;
        }

        // Eliminate an obstacle if needed (grid[i][j] == 1 for an obstacle)
        int nextElimination = curr.k - grid[nextRow][nextCol];
        StepState newState = new StepState(curr.steps + 1, nextRow, nextCol, nextElimination);

        // Check if we can eliminate an obstacle
        if (nextElimination >= 0 && !seen.contains(newState)) {
          seen.add(newState);
          queue.offer(newState);
        }
      }
    }
    // Did not reach target/
    return -1;
  }
}

/**
 * Solution
 *
 * Overview
 *
 * Like many grid search problems where the goal is to find the shortest path,
 * the key to solve this problem is to apply the Breadth-First Search algorithm,
 * as opposed to the Depth-First Search (DFS) algorithm. In this article,
 * we will start with a classic BFS solution. Then on top of BFS, we will
 * introduce a heuristic (greedy) strategy to speed up the algorithm, which
 * eventually transforms our classic BFS algorithm into another classic
 * algorithm called the A* search algorithm.
 *
 * Approach 1: BFS (Breadth-First Search)
 *
 * Intuition
 *
 * In this problem, we must traverse the grid to reach a target cell,
 * while the grid contains some obstacles. If the problem ends here, one could
 * probably tell that this is a classic grid search problem, e.g. the problem of
 * 1730. Shortest Path to Get Food fits the bill exactly.
 *
 * However, the particularity of this problem is that one can eliminate
 * obstacles to a certain extent. This constraint complicates our problem.
 * First of all, if there were no limit on how many obstacles we can eliminate,
 * then the shortest distance to reach the target cell would be the Manhattan
 * distance between the starting cell and the target cell. Likewise, if the
 * quota to eliminate the obstacles is greater than the Manhattan distance,
 * then the shortest distance is guaranteed to be the Manhattan distance.
 * However, we do have a limit on the number of obstacles that we can eliminate
 * along the way. As a result, rather than taking a straightforward path to
 * reach the target, we have to take some detour in certain cases, which implies
 * that we need to explore all possible directions while respecting the
 * constraint.
 *
 * By exploring, we refer to the BFS strategy, rather than DFS.
 * The BFS algorithm works like detecting an object with sonar.
 * A sound wave propagages in all directions with equal speed.
 * At any given moment, all the objects that the sound wave reaches have the
 * same distance to the source of the sound. On the other hand, as soon as the
 * sound wave reaches the object, the path is guaranteed to be the shortest,
 * since the distance is proportional to the time, the more time it takes,
 * the longer the distance is.
 *
 * Given the above intuition of the BFS algorithm, we can rest assured that as
 * soon as we reach the target, the path that leads to the target is the
 * shortest. This is also the rationale for why we should employ the BFS
 * strategy rather than DFS.
 *
 * Algorithm
 *
 * In the canonical implementation of the BFS algorithm, we would employ a
 * queue data structure to maintain the order of exploration. Each element in
 * the queue normally contains two pieces of information: the current position
 * and the distance traveled so far from the starting point.
 *
 * However, in our problem here, we need another piece of information, which is
 * the remaining quota that we can use to eliminate the obstacles.
 * Together with the coordinates, the obstacle elimination quota uniquely
 * constitutes a state during our BFS exploration. For example, in the following
 * graph, we demonstrate two different paths between the start cell and an
 * intermediate cell.
 *
 * Without the obstacle elimination quota, we would only visit the intermediate
 * cell once, while only one of the two paths can lead us to the target,
 * since in one of the paths we don't have sufficient quota to get through.
 * Therefore, it is critical to keep the quota information, so that we can
 * revisit the same cell with different quotas.
 *
 * Implementation
 *
 * We can break down the algorithm into the following steps:
 *
 * The main body of the BFS algorithm consists of a loop around a queue,
 * as well as a set called seen which keeps track of all the states visited
 * along the way so that we don't visit the same state twice. A state refers
 * to a unique combination of coordinates and the remaining quota.
 *
 * At each iteration of the loop, we pop out one element from the queue.
 * The element contains the distance from the starting point as well as the
 * current state which includes the current coordinate and the remaining quotas
 * to eliminate obstacles.
 *
 * Within the same iteration, we evaluate the next moves starting from the
 * popped element. Each move results in a new state and the state is valid if
 * it is within the grid boundaries and has not been visited before.
 * Each valid state is pushed into the queue for later iterations.
 * Meanwhile, we also need to mark the state as visited by adding the state to
 * the seen states set.
 *
 * At any iteration, if we have reached our target,
 * we can return immediately from the loop.
 *
 * Note: before running the BFS traversal, we also perform a quick check
 * to see if we have sufficient quotas to take the most direct path from start
 * to finish regardless of the number of obstacles. If so, the shortest distance
 * to reach the target is the Manhattan distance between the starting cell and
 * the target cell.
 */

 