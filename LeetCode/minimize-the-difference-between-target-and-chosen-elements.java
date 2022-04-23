// https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements/

class Solution {
  public int minimizeTheDifference(int[][] mat, int target) {
    /**
     * We use the dp table for memoization - we store the min difference
     * we can reach from a particular row when we have a particular running sum.
     * dp[i][j] represents the minimum possible abs(target - sum) value possible
     * to be achieved when your running sum is 'j' and you are at the i'th row
     * of the matrix mat.
     */
    Integer[][] dp = new Integer[mat.length][70 * 70 + 1];
    return minDiff(mat, 0, 0, target, dp);
  }

  private int minDiff(int[][] mat, int row, int sum, int target, Integer[][] dp) {
    // base case.
    if (row == mat.length) {
      return Math.abs(sum - target);
    }

    // Since we have Integer array instead of int array, uninitialized vals are
    // null.
    if (dp[row][sum] != null) {
      return dp[row][sum];
    }

    int res = Integer.MAX_VALUE;
    // Go through each integer in this row
    for (int num : mat[row]) {
      res = Math.min(res, minDiff(mat, row + 1, sum + num, target, dp));
    }
    // update memo table.
    dp[row][sum] = res;

    return res;
  }
}