// https://leetcode.com/problems/maximum-subarray/

class Solution {
  // Kadane's algorithm.
  public int maxSubArray(int[] nums) {
    int maxSum = Integer.MIN_VALUE;
    int curSum = 0;
    for (int i = 0; i < nums.length; ++i) {
      curSum = Math.max(curSum + nums[i], nums[i]);
      maxSum = Math.max(maxSum, curSum);
    }
    return maxSum;
  }
}