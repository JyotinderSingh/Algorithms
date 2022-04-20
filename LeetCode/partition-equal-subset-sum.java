// https://leetcode.com/problems/partition-equal-subset-sum/
// https://leetcode.com/problems/partition-equal-subset-sum/discuss/90592/01-knapsack-detailed-explanation
// https://www.youtube.com/watch?v=xCbYmUPvc2Q&t=303s

class Solution {
  /**
   * We basically want to see if we can achieve 'sum/2' amount using a set of
   * numbers
   * from the list. If we can, then the other set automatically amounts to sum/2
   * as well.
   * Hence, we would have successfully divided the list into two equal sum sets.
   */
  public boolean canPartition(int[] nums) {
    int amount = 0;
    for (int num : nums) {
      amount += num;
    }
    if (amount % 2 != 0) {
      return false;
    }

    amount /= 2;

    // Variation of Knapsack.
    // rows = set of numbers considered.
    // columns = if 'columnn#' sum is possible with set of numbers represented by
    // current row.
    int[][] dp = new int[nums.length + 1][amount + 1];

    // 0 sum is possible with 0 elements selected.
    dp[0][0] = 1;
    for (int i = 1; i < dp.length; ++i) {
      for (int j = 1; j < dp[0].length; ++j) {
        // if we do not pick a new number.
        dp[i][j] = dp[i - 1][j];

        // if the current number being considered is smaller than the sum we're
        // trying to reach.
        if (nums[i - 1] <= j) {
          // see if the entry for 'j - nums[i - 1]' amount with all
          // previously seen numbers was non zero - which means it was possible
          // to achieve that number with all the previously seen numbers.
          dp[i][j] |= dp[i - 1][j - nums[i - 1]];
        }
      }
    }
    return dp[dp.length - 1][amount] == 1 ? true : false;
  }
}