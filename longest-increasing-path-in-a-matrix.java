// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

// DFS with memoization: 96%, 90%

class Solution {
  int[][] dirs = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
  int m, n;

  public int longestIncreasingPath(int[][] matrix) {
    m = matrix.length;
    n = matrix[0].length;

    // cache for DFS
    int[][] cache = new int[m][n];

    int result = 0;

    // Perform DFS on entire graph
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        result = Math.max(result, dfs(i, j, matrix, cache));
      }
    }
    return result;
  }

  public int dfs(int row, int col, int[][] matrix, int[][] cache) {
    if (cache[row][col] != 0)
      return cache[row][col];

    for (int[] dir : dirs) {
      int x = row + dir[0], y = col + dir[1];

      // verify preconditions.
      if (0 <= x && x < m && 0 <= y && y < n && matrix[x][y] > matrix[row][col]) {
        cache[row][col] = Math.max(cache[row][col], dfs(x, y, matrix, cache));
      }
    }

    return ++cache[row][col];
  }
}

// First Intuition: 13.8%, 58.9%
// Go through the entire matrix, finding the longest path for each cell.
// We do this by adding 1 to the longest path till each neighbour (with value
// smaller than current cell)
// If we find a longer path, we update the longest path.
// You need to do this multiple times.

class Solution {
  public int longestIncreasingPath(int[][] matrix) {
    int[][] dp = new int[matrix.length][matrix[0].length];
    int rows = matrix.length, cols = matrix[0].length;
    int result = 1;

    // Since the minimum length of longest increasing path for any element is 1
    // which is the element itself.
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        dp[i][j] = 1;
      }
    }

    // this is the max number of times we might need to go around the matrix
    for (int k = 0; k < rows * cols; ++k) {
      // to track if we are still seeing changes in matrix, if not we can return early
      boolean change = false;

      // traverse dp array and update the longest path for each cell
      for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
          int newVal = 1 + findLongestPathToVertex(i, j, dp, matrix);

          if (newVal != dp[i][j]) {
            dp[i][j] = newVal;
            change = true;
          }

          // keep track of result.
          if (dp[i][j] > result) {
            result = dp[i][j];
          }
        }
      }

      // return early if we are not seeing any changes in matrix
      if (!change)
        break;
    }
    return result;
  }

  public int findLongestPathToVertex(int row, int col, int[][] dp, int[][] matrix) {
    int curr = matrix[row][col], path = 0;

    if (row + 1 < dp.length && matrix[row + 1][col] < curr) {
      path = Math.max(dp[row + 1][col], path);
    }
    if (row - 1 >= 0 && matrix[row - 1][col] < curr) {
      path = Math.max(dp[row - 1][col], path);
    }
    if (col + 1 < dp[0].length && matrix[row][col + 1] < curr) {
      path = Math.max(dp[row][col + 1], path);
    }
    if (col - 1 >= 0 && matrix[row][col - 1] < curr) {
      path = Math.max(dp[row][col - 1], path);
    }
    return path;
  }
}