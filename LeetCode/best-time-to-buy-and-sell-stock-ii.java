// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

// Time Complexity: O(n), Space Complexity: O(1)

class Solution {
  public int maxProfit(int[] prices) {
    int maxProfit = 0;
    for (int i = 1; i < prices.length; ++i) {
      if (prices[i] > prices[i - 1]) {
        maxProfit += prices[i] - prices[i - 1];
      }
    }
    return maxProfit;
  }
}

// Time Complexity: O(n), Space Complexity: O(1)

class Solution {
  public int maxProfit(int[] prices) {
    int i = 0;
    int valley = prices[0];
    int peak = prices[0];
    int maxProfit = 0;

    while (i < prices.length - 1) {
      // Get to the next valley where we buy the stock.
      while (i < prices.length - 1 && prices[i] >= prices[i + 1]) {
        i++;
      }
      valley = prices[i];

      // Get to the next peek where we buy the stock.
      while (i < prices.length - 1 && prices[i] <= prices[i + 1]) {
        i++;
      }
      peak = prices[i];

      // Calculate profit.
      maxProfit += peak - valley;
    }
    return maxProfit;
  }
}