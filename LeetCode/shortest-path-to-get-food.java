// https://leetcode.com/problems/shortest-path-to-get-food/

class Solution {
  /**
   * We perform BFS, because it guarantees
   * that we have reached the target cell from the
   * shortest path.
   * By exploring, we refer to the BFS strategy, rather than DFS.
   * The BFS algorithm works like detecting an object with sonar.
   * A sound wave propagages in all directions with equal speed.
   * At any given moment, all the objects that the sound wave
   * reaches have the same distance to the source of the sound.
   * On the other hand, as soon as the sound wave reaches the object,
   * the path is guaranteed to be the shortest, since the distance
   * is proportional to the time, the more time it takes, the longer
   * the distance is. BFS demo
   * Given the above intuition of the BFS algorithm, we can rest
   * assured that as soon as we reach the target, the path that
   * leads to the target is the shortest.
   * This is also the rationale for why we should employ
   * the BFS strategy rather than DFS.
   */
  public int getFood(char[][] grid) {
    int steps = 0;
    int[][] dirs = new int[][] { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
    int m = grid.length, n = grid[0].length;

    Queue<int[]> queue = new LinkedList<>();
    boolean[][] visited = new boolean[m][n];

    // add the starting point to the grid.
    queue.offer(getStart(grid));

    while (!queue.isEmpty()) {
      /*
       * We need to keep track of the queue's size
       * at the start of each iteration, because we need
       * to know what step we are at.
       * All the element's in the queue at the start of
       * the iteration process are at the same distance away
       * from the starting point.
       */
      int size = queue.size();
      for (int i = 0; i < size; ++i) {
        int[] pos = queue.poll();

        int x = pos[0], y = pos[1];

        // Check if current step is solution.
        if (grid[x][y] == '#')
          return steps;

        for (int[] dir : dirs) {
          int newX = pos[0] + dir[0];
          int newY = pos[1] + dir[1];

          if (isValid(newX, newY, grid) && !visited[newX][newY]) {
            visited[newX][newY] = true;
            queue.offer(new int[] { newX, newY });
          }
        }
      }
      steps++;
    }
    return -1;
  }

  private boolean isValid(int x, int y, char[][] grid) {
    return x >= 0 && x < grid.length && y >= 0 && y < grid[0].length
        && grid[x][y] != 'X';
  }

  private int[] getStart(char[][] grid) {
    for (int i = 0; i < grid.length; ++i) {
      for (int j = 0; j < grid[0].length; ++j) {
        if (grid[i][j] == '*') {
          return new int[] { i, j };
        }
      }
    }
    // Should not reach here.
    throw new RuntimeException("Did not find a starting point.");
  }
}