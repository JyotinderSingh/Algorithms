// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

class Solution {
  public int maxProfit(int[] prices) {
    if (prices.length == 0)
      return 0;

    int leastPrice = prices[0];
    int maxProfitTillNow = 0;
    int[] maxProfitToday = new int[prices.length];
    // first pass.
    // This will allow us to get the max profit possible till each day.
    for (int i = 0; i < prices.length; ++i) {
      maxProfitTillNow = Math.max(maxProfitTillNow, prices[i] - leastPrice);
      leastPrice = Math.min(leastPrice, prices[i]);
      maxProfitToday[i] = maxProfitTillNow;
    }

    // second pass.
    // now we can start simulating a second transaction.
    // at the beginning of each transaction, we would already
    // know the max profit that would be possible till the day before that.
    int finalProfit = 0, maxPrice = prices[prices.length - 1];
    for (int i = prices.length - 1; i > 0; i--) {
      finalProfit = Math.max(finalProfit, maxPrice - prices[i] + maxProfitToday[i - 1]);
      maxPrice = Math.max(maxPrice, prices[i]);
    }

    // return max profit (it is possible we don't need to sell today).
    return Math.max(finalProfit, maxProfitToday[maxProfitToday.length - 1]);
  }
}