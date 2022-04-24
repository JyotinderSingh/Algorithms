// https://leetcode.com/problems/coin-change/

import java.util.Arrays;

// Time: O(Amount * numCoins), Space: O(Amount)

class Solution {
  public int coinChange(int[] coins, int amount) {
    // amount + 1 is an unreachable value since
    int max = amount + 1;
    int[] change = new int[amount + 1];
    Arrays.fill(change, max);

    // min value of coin is 1, so we can never create 0 amount.
    change[0] = 0;

    // Calculate the min number of coins needed for each smaller amount
    // leading up to the main amount in bottom up fashion.
    for (int i = 1; i <= amount; ++i) {
      for (int coin : coins) {
        // check if the coin denomination is less than the amount
        // we are trying to create.
        if (coin <= i) {
          change[i] = Math.min(change[i], change[i - coin] + 1);
        }
      }
    }

    return change[amount] == max ? -1 : change[amount];
  }
}