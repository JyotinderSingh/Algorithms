// https://leetcode.com/problems/search-in-rotated-sorted-array/

// Single pass
class Solution {
  public int search(int[] nums, int target) {
    int start = 0, end = nums.length - 1;

    while (start <= end) {
      int mid = start + (end - start) / 2;
      if (nums[mid] == target)
        return mid;

      // left part is un-rotated.
      else if (nums[mid] >= nums[start]) {
        if (target >= nums[start] && target < nums[mid])
          end = mid - 1;
        else
          start = mid + 1;
      }
      // right part is unrotated.
      else {
        if (target <= nums[end] && target > nums[mid])
          start = mid + 1;
        else
          end = mid - 1;
      }
    }
    return -1;
  }
}

// Double pass
class Solution {
  int[] nums;
  int target;

  public int find_rotate_index(int left, int right) {
    if (nums[left] < nums[right])
      return 0;

    while (left <= right) {
      int pivot = (left + right) / 2;
      if (nums[pivot] > nums[pivot + 1])
        return pivot + 1;
      else {
        if (nums[pivot] < nums[left])
          right = pivot - 1;
        else
          left = pivot + 1;
      }
    }
    return 0;
  }

  public int search(int left, int right) {
    /*
     * Binary search
     */
    while (left <= right) {
      int pivot = (left + right) / 2;
      if (nums[pivot] == target)
        return pivot;
      else {
        if (target < nums[pivot])
          right = pivot - 1;
        else
          left = pivot + 1;
      }
    }
    return -1;
  }

  public int search(int[] nums, int target) {
    this.nums = nums;
    this.target = target;

    int n = nums.length;

    if (n == 1)
      return this.nums[0] == target ? 0 : -1;

    int rotate_index = find_rotate_index(0, n - 1);

    // if target is the smallest element
    if (nums[rotate_index] == target)
      return rotate_index;
    // if array is not rotated, search in the entire array
    if (rotate_index == 0)
      return search(0, n - 1);
    if (target < nums[0])
      // search in the right side
      return search(rotate_index, n - 1);
    // search in the left side
    return search(0, rotate_index);
  }
}