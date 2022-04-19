// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
  public int maxProfit(int[] prices) {
    int maxProfit = 0;
    int profitToday = 0;
    int leastPrice = Integer.MAX_VALUE;
    for (int price : prices) {
      profitToday = price - leastPrice;
      leastPrice = Math.min(leastPrice, price);
      maxProfit = Math.max(maxProfit, profitToday);
    }
    return maxProfit;
  }
}

class Solution {
  public int maxProfit(int[] prices) {
    // We want to keep tracking the smallest value that we see,
    // since we would probably want to buy at that price.
    int minPrice = Integer.MAX_VALUE;
    int maxProfit = Integer.MIN_VALUE;

    // go through all the prices
    for (int price : prices) {
      // Is this the lowest price we have found so far?
      if (price < minPrice) {
        minPrice = price;
      } else if (price - minPrice > maxProfit) {
        // is this the highest selling price we have found so far?
        maxProfit = price - minPrice;
      }
    }
    return maxProfit;
  }
}