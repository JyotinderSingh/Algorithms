// https://leetcode.com/problems/minimum-path-sum/

// Time Complexity: O(mn), Space Complexity: O(mn)
class Solution {
  public int minPathSum(int[][] grid) {
    int rows = grid.length, cols = grid[0].length;
    int[][] dp = new int[rows][cols];

    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        // Elements in first row (except the one element in first column).
        if (i == 0 && j != 0) {
          dp[i][j] = grid[i][j] + dp[i][j - 1];
        }
        // Elements in first column (except the one in the first row).
        else if (j == 0 && i != 0) {
          dp[i][j] = grid[i][j] + dp[i - 1][j];
        }
        // All elements except ones in first row or first column.
        else if (i != 0 && j != 0) {
          dp[i][j] = grid[i][j] + Math.min(dp[i - 1][j], dp[i][j - 1]);
        }
        // Element at (0, 0).
        else {
          dp[i][j] = grid[i][j];
        }
      }
    }

    return dp[rows - 1][cols - 1];
  }
}

// Time Complexity: O(mn), Space Complexity: O(1)

class Solution {
  public int minPathSum(int[][] grid) {
    int rows = grid.length, cols = grid[0].length;

    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        // Elements in first row (except the one element in first column).
        if (i == 0 && j != 0) {
          grid[i][j] = grid[i][j] + grid[i][j - 1];
        }
        // Elements in first column (except the one in the first row).
        else if (j == 0 && i != 0) {
          grid[i][j] = grid[i][j] + grid[i - 1][j];
        }
        // All elements except ones in first row or first column.
        else if (i != 0 && j != 0) {
          grid[i][j] = grid[i][j] + Math.min(grid[i - 1][j], grid[i][j - 1]);
        }
        // Element at (0, 0).
        // else {
        // grid[i][j] = grid[i][j];
        // }
      }
    }

    return grid[rows - 1][cols - 1];
  }
}