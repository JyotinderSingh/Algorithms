// https://leetcode.com/problems/maximum-number-of-points-with-cost/

// Optimized monotnoically increasing function solution.
// Time: O(m*n), Space: O(n)
// Understand the initial approach solution first, then come to this.
// Initial approach given below this solution.
// Explanation: https://leetcode.com/problems/maximum-number-of-points-with-cost/discuss/1344908/C%2B%2BJavaPython-3-DP-Explanation-with-pictures-O(MN)-Time-O(N)-Space
class Solution {
  public long maxPoints(int[][] points) {
    int rows = points.length, cols = points[0].length;
    long[] prev = new long[cols];

    // for the first row, we can directly populate prev array with the
    // elements from the first row of the points matrix, since there is no
    // prev answers for it.
    for (int j = 0; j < cols; ++j)
      prev[j] = points[0][j];

    for (int i = 1; i < rows; ++i) {
      // Build the leftMax array.
      long[] lft = new long[cols];
      lft[0] = prev[0];
      for (int j = 1; j < cols; ++j) {
        lft[j] = Math.max(lft[j - 1] - 1, prev[j]);
      }

      // build the rightMax array.
      long[] rgt = new long[cols];
      rgt[cols - 1] = prev[cols - 1];
      for (int j = cols - 2; j >= 0; --j) {
        rgt[j] = Math.max(rgt[j + 1] - 1, prev[j]);
      }

      // Get the max score for the current row
      long[] cur = new long[cols];
      for (int j = 0; j < cols; ++j) {
        cur[j] = points[i][j] + Math.max(lft[j], rgt[j]);
      }

      // Now update prev array to become equal to cur for next iteration.
      prev = cur;
    }

    long ans = 0;

    // prev now contains the max scores possible at each location at the last
    // row, the max of these is the result.
    for (int i = 0; i < cols; ++i) {
      ans = Math.max(ans, prev[i]);
    }
    return ans;
  }
}

// Initial approach, gives TLE
// Time: O(m * n * n), Space: O(m * n)

class Solution {
  public long maxPoints(int[][] points) {
    int rows = points.length, cols = points[0].length;
    long[][] dp = new long[points.length][points[0].length];
    long res = 0;

    // populate the first row with the max score possible in each cell.
    for (int col = 0; col < cols; ++col) {
      dp[0][col] = points[0][col];
      res = Math.max(res, dp[0][col]);
    }

    // Start calculating the score for each cell in the rest of the rows.
    for (int row = 1; row < rows; ++row) {
      for (int col = 0; col < cols; ++col) {
        dp[row][col] = getMaxScoreAtCell(row, col, points, dp);
        res = Math.max(res, dp[row][col]);
      }
    }
    return res;
  }

  long getMaxScoreAtCell(int row, int col, int[][] points, long[][] dp) {
    long res = Long.MIN_VALUE;
    // Calculate max score possible at each cell.
    for (int j = 0; j < points[0].length; ++j) {
      res = Math.max(res, dp[row - 1][j] + points[row][col] - Math.abs(col - j));
    }
    return res;
  }
}