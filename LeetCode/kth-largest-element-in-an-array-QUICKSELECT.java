// https://leetcode.com/problems/kth-largest-element-in-an-array/

import java.util.concurrent.ThreadLocalRandom;

class Solution {
  int[] nums;

  /*
   * The main point to be kept in mind is that the k'th largest element
   * will be present at the (n - k)'th position in the array
   * Keep track of the 'left' and 'right' space in which the
   * k'th largest element can possible be, we will use these bounds
   * to know what section to actually partition around a chosen pivot
   */
  public int findKthLargest(int[] nums, int k) {
    this.nums = nums;
    int n = nums.length;
    int left = 0, right = n - 1;

    // While the bounds stay valid, continue doing directed partitioning.
    while (left <= right) {
      // Pick a random pivot in bounds [left, right]
      int chosenPivotIndex = ThreadLocalRandom.current().nextInt(left, right + 1);

      /*
       * Execute the actual partitioning and get back the final position
       * of the pivot we chose after the partitioning is over
       */
      int finalIndexOfChosenPivot = partition(left, right, chosenPivotIndex);

      // Solution case.
      if (finalIndexOfChosenPivot == n - k) {
        /*
         * Found. The pivot is on index n - k. This is literally its final position
         * if the array we were given had been sorted. See how we saved work? We don't
         * need to sort the whole array
         */
        return this.nums[finalIndexOfChosenPivot];
      }
      // Fix the bounds.
      else if (finalIndexOfChosenPivot > n - k) {
        /*
         * k'th largest must be in the left partition. We "overshot" and need to
         * go left (and we do this by narrowing the right bound)
         */
        right = finalIndexOfChosenPivot - 1;
      } else {
        /*
         * k'th largest must be in the right partition. We "undershot" and need to
         * go right (and we do this by narrowing the left bound)
         */
        left = finalIndexOfChosenPivot + 1;
      }

    }
    // return 0 written just to avoid warnings
    return 0;
  }

  /*
   * So this subroutine is exactly what we do in QuickSort - partition around the
   * value
   * that the 'pivotIndex' holds
   * Result is [items < pivot....pivot....items > pivot]
   */
  int partition(int left, int right, int pivotIndex) {
    // Grab the value at the index we passed in.
    int pivotValue = nums[pivotIndex];

    int lesserItemsTailIndex = left;

    /*
     * Move the item at 'pivotIndex' OUT OF THE WAY. We are about to
     * bulldoze through the partition space and we don't want it in
     * the way
     */
    swap(pivotIndex, right);

    for (int i = left; i < right; ++i) {
      if (nums[i] < pivotValue) {
        swap(i, lesserItemsTailIndex);
        lesserItemsTailIndex++;
      }
    }

    swap(lesserItemsTailIndex, right);
    return lesserItemsTailIndex;
  }

  void swap(int idx1, int idx2) {
    int temp = nums[idx1];
    nums[idx1] = nums[idx2];
    nums[idx2] = temp;
  }
}