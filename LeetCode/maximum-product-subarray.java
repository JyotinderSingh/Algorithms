// https://leetcode.com/problems/maximum-product-subarray/

class Solution {
  public int maxProduct(int[] nums) {
    int res = nums[0];

    for (int i = 1, curMax = res, curMin = res; i < nums.length; ++i) {

      // If we encounter a negative number, the largest product that we've found
      // till now, will become the smallest once multiplied.
      // And the smallest product we've found till now will become the largest
      // once multiplied
      if (nums[i] < 0) {
        int temp = curMin;
        curMin = curMax;
        curMax = temp;
      }

      curMin = Math.min(nums[i], nums[i] * curMin);
      curMax = Math.max(nums[i], nums[i] * curMax);
      res = Math.max(res, curMax);
    }
    return res;
  }
}