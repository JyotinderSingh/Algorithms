// https://leetcode.com/problems/find-peak-element/

class Solution {
  public int findPeakElement(int[] nums) {
    int left = 0, right = nums.length - 1;
    while (left < right) {
      int mid = left + (right - left) / 2;

      if (nums[mid] > nums[mid + 1]) {
        // we want to maintain the right pointer at the possible peak value.
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return left; // or right.
  }
}