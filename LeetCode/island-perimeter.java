// https://leetcode.com/problems/island-perimeter/

class Solution {
  public int islandPerimeter(int[][] grid) {
    int sum = 0;
    for (int i = 0; i < grid.length; ++i) {
      for (int j = 0; j < grid[0].length; ++j) {
        if (grid[i][j] == 1) {
          // Top edge
          sum += (i == 0 || grid[i - 1][j] == 0) ? 1 : 0;
          // left edge
          sum += (j == 0 || grid[i][j - 1] == 0) ? 1 : 0;
          // bottom edge
          sum += (i == grid.length - 1 || grid[i + 1][j] == 0) ? 1 : 0;
          // right edge.
          sum += (j == grid[i].length - 1 || grid[i][j + 1] == 0) ? 1 : 0;
        }
      }
    }

    return sum;
  }
}

// DFS
