// https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/

import java.util.HashSet;
import java.util.PriorityQueue;

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
    int estimation;
    int[] target;

    public StepState(int steps, int row, int col, int k, int[] target) {
      this.steps = steps;
      this.row = row;
      this.col = col;
      this.k = k;

      this.target = target;
      int manhattanDistance = target[0] - row + target[1] - col;
      // h(n) = manhattan distance, g(n) = 0
      // estimation = h(n) + g(n)
      this.estimation = manhattanDistance + steps;

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

    // MIN HEAP to store the states, and sort them in ascending order of estimation
    // so that we choose the cheapest estimated path first.
    PriorityQueue<StepState> queue = new PriorityQueue<>(1, (a, b) -> a.estimation - b.estimation);
    HashSet<StepState> seen = new HashSet<>();

    // Add the start state to the queue.
    StepState start = new StepState(0, 0, 0, k, target);
    queue.offer(start);
    seen.add(start);

    while (!queue.isEmpty()) {
      StepState curr = queue.poll();

      // we can reach the target in the shortest path (manhattan distance),
      // even if the remaining steps are all obstacles.
      int remainingDistance = curr.estimation - curr.steps;
      if (remainingDistance <= curr.k) {
        return curr.estimation;
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
        StepState newState = new StepState(curr.steps + 1, nextRow, nextCol, nextElimination,
            target);

        // Check if we can eliminate an obstacle
        if (nextElimination >= 0 && !seen.contains(newState)) {
          seen.add(newState);
          queue.offer(newState);
        }
      }
    }
    // Did not reach target
    return -1;
  }
}

/**
 * Approach 2: A* (A Star) Algorithm
 * <p>
 * Intuition
 * <p>
 * In the above BFS approach, one might notice that when at any specific
 * position, we would systematically explore the surrounding neighbors in all
 * four directions, due to the nature of BFS.
 * <p>
 * However, the action might seem conterintuitive or sub-optimal. Since the
 * destination is located in the lower-right corner of the grid, in order to
 * find the shortest path, the optimal directions to explore should be either
 * right or down, rather than left or up.
 *
 * As depicted in the above image, the optimal steps to explore should be the
 * ones in green (right and down), rather than the ones in orange.
 *
 * Therefore, one idea to improve our BFS approach is to prioritize exploring
 * the most promising directions at each step. Through prioritization, we can
 * speed up the algorithm by reducing the time spent exploring less promising
 * paths.
 * This idea leads us to the A* search algorithm, which is yet another classic
 * path finding algorithm that uses a heuristic.
 *
 * Note: we cannot exclude (or prune) those less promising directions, otherwise
 * we might miss the correct path because sometimes we have to take a detour in
 * order to reach the destination.
 *
 * Algorithm
 *
 * A* (pronounced as A star) is also known as an informed search algorithm or
 * best-first search. Because at each step of exploration, it makes the best and
 * informed decision on the next steps, i.e. it prioritizes the steps that are
 * the most promising. Specifically, this prioritization strategy can be
 * expressed as A* selects a path that minimizes the following function:
 * f(n)=g(n)+h(n)
 * f(n)=g(n)+h(n)
 *
 * n: a specific step during the exploration.
 * g(n): the cost to reach the step n. Here, the cost refers to the distance
 * traveled so far to the step n.
 * h(n): a heuristic estimation on the cost to reach the destination from the
 * step n. Here, the cost refers to the distance ahead.
 * f(n): the estimated total cost to reach the destination if one takes the
 * step n.
 *
 * With the defined function, A* algorithm has a deterministic way to evaluate
 * each potential step, and then make what it believes to be the best decision
 * at each step.
 * The problem boils down to defining the above functions for our scenario, in
 * order to apply the A* algorithm. Specifically,
 * 
 * g(n) would be the number of steps that one has taken to reach n. And h(n)
 * would be the Manhattan distance from n to the destination, which is the
 * shortest path to reach the destination.
 *
 * The most important property of our heuristic h(n) function is that the
 * function should be admissible, i.e. it never overestimates the cost.
 * Otherwise, it could not guarantee that the path we find is the shortest one.
 * To understand the admissible property, let us take a metaphor. In a football
 * tournament, we want to select the best team in the end. If we overestimate
 * the incompetence of a team, i.e. we downplay the potential of the team, we
 * might prematurely disqualify or ignore the team. As a result, we may predict
 * that a not-so-good team will win the championship, while in reality, the team
 * we disqualified or ignored happens to be the best team.
 *
 * Implementation
 *
 * The A* algorithm provides a more optimized path selection strategy,
 * on top of the BFS approach. Therefore, we can implement the A* algorithm
 * while keeping the bulk of our previous BFS approach intact. We will still
 * use a queue to keep track of the order of visits. And we will still use a set
 * to keep track of the visited states so that we do not revisit any previously
 * explored paths.
 *
 * Additionally, here are the modifications that we will make:
 *
 * Rather than using a normal queue, we use a priority queue to store the order
 * of visits. The order of visits is based on the estimated total cost function
 * f(n) that we defined. With the priority queue, the step that has potentially
 * the lowest cost will be visited first.
 *
 * For each element in the queue, we add one more piece of information which is
 * the estimated total cost to reach the destination at each step.
 * This estimation will be used to prioritize each potential next step.
 *
 * We add another heuristic condition that allows us to determine the length of
 * the shortest path without exploration. The condition is as follows:
 *
 * At any step, if the remaining quota to eliminate the obstacles is larger than
 * the length of the estimated shortest path (i.e. manhattan distance between
 * the current step and the destination), then the length of the remaining path
 * is the manhattan distance.
 *
 * The condition can also be interpreted as if we have sufficient capacity to
 * remove any obstacle along the way, we will simply take the shortest path to
 * reach the destination, without the need for further exploration.
 *
 * We apply the condition at the beginning of each iteration of the loop.
 *
 */