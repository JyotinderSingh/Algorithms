
// https://leetcode.com/problems/trapping-rain-water-ii/
import java.util.PriorityQueue;

/**
 * I spent the entire day thinking about this problem, reading blogs, and
 * finally figured this out (hopefully the feeling is true). Here are some
 * thoughts and summary.
 * 
 * What determines the amount of water can a bar can hold? It is the min height
 * of the max heights along all paths to the boundary (not just 4 direction!!!,
 * which was my first intuition) Look at the example below. If we add 2 units of
 * water into the 1 in the center, it will overflow to 0.
 * 0 0 3 0 0
 * 0 0 2 0 0
 * 3 2 1 2 3
 * 0 0 2 0 0
 * 0 0 3 0 0
 * 
 * Just like 1-D two pointer approach, we need to find some boundary. Because
 * all boundary cells cannot hold any water for sure, we use them as the initial
 * boundary naturally.
 * 
 * Then which bar to start? Find the min bar (let's call it A) on the boundary
 * (heap is a natural choice), then do 1 BFS (4 directions). Why BFS? Because we
 * are sure that the amount of water that A's neighbors can hold is only
 * determined by A now for the same reason in 1D two-pointer approach.
 * 
 * How to update the heap during BFS
 * Step 1. Remove the min bar A from the heap
 * Step 2. If A's neighbor B's height is higher, it cannot hold any water. Add
 * it to the heap
 * Step 3. If B's height is lower, it can hold water and the amount of water
 * should be height_A - height_B. Here comes the tricky part, we still add B's
 * coordinate into the heap, BUT change its height to A's height because A is
 * the max value along this path (for this reason we cannot just use heightMap
 * and need a class/array to store it's coordinates and UPDATED height). And we
 * can think of B as a replacement of A now and never worry about A again.
 * Therefore a new boundary is formed and we can repeat this process again.
 * 
 * Hope it helps!
 */

class Solution {
  public class Cell {
    int row;
    int col;
    int height;

    public Cell(int row, int col, int height) {
      this.row = row;
      this.col = col;
      this.height = height;
    }
  }

  public int trapRainWater(int[][] heights) {
    if (heights == null || heights.length == 0 || heights[0].length == 0) {
      return 0;
    }

    // Min heap for storing cells, sorts based on cell height.
    PriorityQueue<Cell> pq = new PriorityQueue<>(1, (a, b) -> a.height - b.height);

    int rows = heights.length;
    int cols = heights[0].length;
    boolean[][] visited = new boolean[rows][cols];

    // Start with adding all the cells on the border to the PQ.
    for (int i = 0; i < rows; ++i) {
      visited[i][0] = true;
      visited[i][cols - 1] = true;
      pq.offer(new Cell(i, 0, heights[i][0]));
      pq.offer(new Cell(i, cols - 1, heights[i][cols - 1]));
    }
    for (int j = 0; j < cols; ++j) {
      visited[0][j] = true;
      visited[rows - 1][j] = true;
      pq.offer(new Cell(0, j, heights[0][j]));
      pq.offer(new Cell(rows - 1, j, heights[rows - 1][j]));
    }

    // Starting from the border, check the shortest cell that was visited
    // and check its neighbours. If the neighbour is shorter - it means it can
    // collect water. Add the amount of water it can collect and update its height
    // as (the cell's height + water it can trap).
    // Do this for all the cells and their neighbours.
    int[][] dirs = new int[][] { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
    int result = 0;

    while (!pq.isEmpty()) {
      Cell cell = pq.poll();
      for (int[] dir : dirs) {
        int row = cell.row + dir[0];
        int col = cell.col + dir[1];
        if (row >= 0 && row < rows && col >= 0 && col < cols && !visited[row][col]) {
          visited[row][col] = true;
          result += Math.max(0, cell.height - heights[row][col]);
          pq.offer(new Cell(row, col, Math.max(heights[row][col], cell.height)));
        }
      }
    }

    return result;
  }
}