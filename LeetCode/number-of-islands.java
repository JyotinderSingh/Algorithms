// https://leetcode.com/problems/number-of-islands/

class Solution {
  public int numIslands(char[][] grid) {
    int count = 0;
    for (int i = 0; i < grid.length; ++i) {
      for (int j = 0; j < grid[0].length; ++j) {
        if (grid[i][j] == '1') {
          count++;
          coverArea(grid, i, j);
        }
      }
    }
    return count;
  }

  void coverArea(char[][] grid, int r, int c) {
    if (r < 0 || r >= grid.length || c < 0 || c >= grid[0].length || grid[r][c] == '0') {
      return;
    }

    grid[r][c] = '0';
    coverArea(grid, r + 1, c);
    coverArea(grid, r, c + 1);
    coverArea(grid, r - 1, c);
    coverArea(grid, r, c - 1);
  }
}