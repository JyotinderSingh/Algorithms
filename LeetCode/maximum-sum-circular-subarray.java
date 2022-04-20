// https://leetcode.com/problems/maximum-sum-circular-subarray/

class Solution {
  public int maxSubarraySumCircular(int[] nums) {
    int maxNonCircular = kadane(nums);

    /*
     ow if we wanna find the circular sum, we need to realise
     hat it'll simply be the sum of the entire array, with the
     ost negatively affecting contiguous chunk of numbers removed
     hat chunk is basically the chunk that adds up to the minimum sum
     o find that sum, we use the same algorithm, except that now before
     eeding our array into it, we negate all the elements - this means that
     he chunk of numbers with the min sum is now the chunk with the max sum
     nd we add this sum to the totalSum of original array to get the result
     
    int totalSum = 0;
    for (int i = 0; i < nums.length; ++i) {
      totalSum += nums[i];
      nums[i] = -nums[i];
    }
    int minSumInverted = kadane(nums);
    int maxCircular = totalSum + minSumInverted;

    // if none of the elements was selected in the circular ordering
    if (maxCircular == 0) {
      return maxNonCircular;
    }
    return Math.max(maxNonCircular, maxCircular);
  }

  int kadane(int[] nums) {
    int res = Integer.MIN_VALUE, curMax = -50000;
    for (int i = 0; i < nums.length; ++i) {
      curMax = Math.max(nums[i], curMax + nums[i]);
      res = Math.max(res, curMax);
    }
    return res;
  }
}