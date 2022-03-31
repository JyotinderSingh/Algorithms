// https://leetcode.com/problems/count-pairs-in-two-arrays/

import java.util.Arrays;


class Solution {
  public long countPairs(int[] nums1, int[] nums2) {
    /**
     * nums1[i] + nums1[j] > nums2[i] + nums2[j]
     * rewrite:
     * nums1[i] - nums2[i] > nums2[j] - nums1[j]
     * let nums1[i] - nums2[i] = fn(i)
     * at this point the (i < j) constraint becomes meaningless
     * since we can rewrite it as
     * fn(i) > - fn(j)
     * fn(i) + fn(j) > 0 --- (1)
     * Store fn(x) into a new array, sort it
     * and use two pointer approach to find number of
     * combinations satisfying eq. 1
     */
    int[] nums = new int[nums1.length];
    for (int i = 0; i < nums.length; ++i) {
      nums[i] = nums1[i] - nums2[i];
    }
    Arrays.sort(nums);

    int left = 0, right = nums.length - 1;
    long result = 0;
    while (left < right) {
      if (nums[left] + nums[right] > 0) {
        result += right - left;

        // We counted all pairs in this range.
        // Shrink the upper bound.
        right--;
      } else {
        // we found no suitable pairs in this range,
        // possibility is that our lower bound is too small
        // so move the lower bound to the right to increase
        // total sum.
        left++;
      }
    }
    return result;
  }
}