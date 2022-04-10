// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

// Time:  O(logn), Space O(1)
class Solution {
  public int[] searchRange(int[] nums, int target) {
    return new int[] { findLeftBound(nums, target), findRightBound(nums, target) };
  }

  int findLeftBound(int[] nums, int target) {
    int idx = -1;
    int left = 0, right = nums.length - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;

      // We want to find the left-most occurrence,
      // so we try to reduce the right bound over the '>=' range.
      // This means we already reduce the search space for '>' case
      // like in general B.S. But now even if we find '==' case
      // we will still reduce it towards the left to find the left-most
      // bound.
      if (nums[mid] >= target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }

      // Keep track of latest index which has target element.
      if (nums[mid] == target) {
        idx = mid;
      }
    }
    return idx;
  }

  int findRightBound(int[] nums, int target) {
    int idx = -1;
    int left = 0, right = nums.length - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;

      // We want to find the right-most occurrence,
      // so we try to reduce the left bound over the '<=' range.
      // This means we already reduce the search space for '<' case
      // like in general B.S. But now even if we find '==' case
      // we will still reduce it towards the right to find the right-most
      // bound.
      if (nums[mid] <= target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }

      if (nums[mid] == target) {
        idx = mid;
      }
    }
    return idx;
  }
}