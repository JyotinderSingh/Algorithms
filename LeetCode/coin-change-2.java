// https://leetcode.com/problems/coin-change-2/

class Solution {
  public int change(int amount, int[] coins) {
    // dp[i][j] represents number of ways to get to amount 'j'
    // using only the first 'i' coins.
    int[][] dp = new int[coins.length + 1][amount + 1];

    // Initialize the base case:
    // 1. How many ways are there to get 0 amount?
    // A. 1 way -> pick up no coins.
    // Hence, we initialize each element in first column with 1.
    for (int row = 0; row < dp.length; ++row) {
      dp[row][0] = 1;
    }
    // 2. How many ways are there to get any amount greater than 0
    // using 0 coins.
    // A. 0 ways, since we can't create non zero amount with 0 coins.
    // Initialize all columns (greater than 0) in first row with 0.
    for (int col = 1; col < dp[0].length; ++col) {
      dp[0][col] = 0;
    }

    // Number of ways to get amount 'j' using first 'i' coins:
    // Case 1: We don't choose any coin, the number of ways will
    // be the same as the number of ways to create amount 'j'
    // using 'i - 1' coins. (dp[i - 1][j]).
    // Case 2: Choose i'th coin, then the number of ways will be
    // equal to the number of ways to get amount 'j - coinValue'.
    // Hence,
    // dp[i][j] = dp[i - 1][j] + dp[i][j - coin[i - 1]];
    for (int row = 1; row < dp.length; ++row) {
      for (int col = 1; col < dp[0].length; ++col) {
        // If we don't choose the current coin;
        dp[row][col] = dp[row - 1][col];

        // Can we pick the current coin?
        if (coins[row - 1] <= col) {
          // Add the Number of ways to get to 'col - coinValue' amount.
          dp[row][col] += dp[row][col - coins[row - 1]];
        }
      }
    }

    return dp[dp.length - 1][dp[0].length - 1];
  }
}