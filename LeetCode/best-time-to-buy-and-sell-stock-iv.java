// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
// https://www.youtube.com/watch?v=oDhu5uGq_ic
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/discuss/54117/Clean-Java-DP-solution-with-comment

class Solution {
  public int maxProfit(int k, int[] prices) {
    int n = prices.length;

    // for k transactions we'll need 2k days in total
    // if the number of days is less than that - we can
    // just treat this as special case where infinite transactions are possible.
    if (k >= n / 2) {
      int maxProfit = 0;
      for (int i = 1; i < n; ++i) {
        if (prices[i] > prices[i - 1]) {
          maxProfit += prices[i] - prices[i - 1];
        }
      }
      return maxProfit;
    }

    // Each element in the dp table at dp[i][j] represents the max profit
    // possible at day j with at max i transactions.
    int[][] dp = new int[k + 1][n];
    // Optimization to remember the local maximum profit possible for (i - 1)
    // transactions
    // when we are solving for i transactions.
    int localMax = Integer.MIN_VALUE;
    for (int i = 1; i <= k; ++i) {
      for (int j = 1; j < n; ++j) {
        // update localMax.
        localMax = Math.max(localMax, -prices[j - 1] + dp[i - 1][j - 1]);
        // See if we can get maxProfit by skipping or selling.
        dp[i][j] = Math.max(dp[i][j - 1], prices[j] + localMax);
      }
      localMax = Integer.MIN_VALUE;
    }
    return dp[k][n - 1];
  }
}