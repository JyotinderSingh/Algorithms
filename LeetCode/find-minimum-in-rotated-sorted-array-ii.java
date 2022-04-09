// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

class Solution {
  public int findMin(int[] nums) {
    int low = 0, high = nums.length - 1;

    while (low < high) {
      int pivot = low + (high - low) / 2;

      /**
       * The pivot element resides in the same half as the upper bound element.
       * Therefore, the desired minimum element should reside to the left-hand
       * side of pivot element.
       * As a result, we then move the upper bound down to the pivot index,
       * i.e. high = pivot.
       */
      if (nums[pivot] < nums[high]) {
        high = pivot;
      } else if (nums[pivot] > nums[high]) {
        /**
         * The pivot element resides in the different half of array as the upper bound
         * element.
         * Therefore, the desired minimum element should reside to the
         * right-hand side of the pivot element.
         * As a result, we then move the lower bound up next to the pivot index,
         * i.e. low = pivot + 1.
         */
        low = pivot + 1;
      } else {
        /**
         * In this case, we are not sure which side of the pivot that the
         * desired minimum element would reside.
         * To further reduce the search scope, a safe measure would be to reduce
         * the upper bound by one (i.e. high = high - 1), rather than moving
         * aggressively to the pivot point.
         * The above strategy would prevent the algorithm from stagnating
         * (i.e. endless loop). More importantly, it maintains the correctness
         * of the procedure, i.e. we would not end up with skipping the desired
         * element.
         */
        high -= 1;
      }
    }
    return nums[low];
  }
}