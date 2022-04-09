// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
  public int findMin(int[] nums) {
    // If the list has just one element then return that element.
    if (nums.length == 1) {
      return nums[0];
    }

    // initialize left and right pointers.
    int left = 0, right = nums.length - 1;

    // if the lat element is greater than the first element, there is no rotation.
    if (nums[right] > nums[0]) {
      return nums[0];
    }

    while (left <= right) {
      // Find the mid element.
      int mid = left + (right - left) / 2;

      // If the mid element is greater than its next element then (mid + 1)
      // is the smallest.
      // This would be the point of change - from higher to lower.
      if (nums[mid] > nums[mid + 1]) {
        return nums[mid + 1];
      }

      // If the mid element is lesser than its prev element,
      // then mid is the smallest element.
      if (nums[mid] < nums[mid - 1]) {
        return nums[mid];
      }

      // if the mid element's value is greater than the 0th element
      // that would mean the least value is still somewhere to the right
      // as we are still dealing with elements greater than nums[0].
      if (nums[mid] > nums[0]) {
        left = mid + 1;
      } else {
        // if nums[0] is greater than the mid value, then this means the
        // smallest value is somewhere to the left.
        right = mid - 1;
      }
    }
    return -1;
  }
}