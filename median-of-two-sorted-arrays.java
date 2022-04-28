// https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
  public double findMedianSortedArrays(int[] nums1, int[] nums2) {
    // if nums1 length is greater than switch them so that nums1 is smaller than
    // nums2.
    if (nums1.length > nums2.length) {
      return findMedianSortedArrays(nums2, nums1);
    }

    int x = nums1.length;
    int y = nums2.length;

    // First partition can be before the 0th element.
    int low = 0;
    // Last partition can be after the last element.
    int high = x;

    while (low <= high) {
      int partitionX = low + (high - low) / 2;

      /*
       * We want to partition the arrays in such a way that
       * partitionX + partitionY = (total no. of elements) / 2
       * [as partition value is indirectly also equal to number of elements
       * on the left of that point]
       * we add a 1 to x+y just to make the calculation a little easier in both the
       * cases
       * of even and odd number of total elements
       */
      int partitionY = ((x + y + 1) / 2) - partitionX;

      int maxLeftX = partitionX == 0 ? Integer.MIN_VALUE : nums1[partitionX - 1];
      int minRightX = partitionX == x ? Integer.MAX_VALUE : nums1[partitionX];

      int maxLeftY = (partitionY == 0) ? Integer.MIN_VALUE : nums2[partitionY - 1];
      int minRightY = (partitionY == y) ? Integer.MAX_VALUE : nums2[partitionY];

      /*
       * We have partitioned array at correct place
       * Now get max of left elements and min of right elements to get
       * the median in case of even length combined array size
       * or get max of left for odd length combined array size.
       */
      if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
        if ((x + y) % 2 == 0) {
          return (double) (Math.max(maxLeftX, maxLeftY) + Math.min(minRightX, minRightY)) / 2;
        } else {
          return (double) Math.max(maxLeftX, maxLeftY);
        }
      } else if (maxLeftX > minRightY) {
        // we are too far on right side for partitionX. Go on left side.
        high = partitionX - 1;
      } else {
        // we are too far on left side for partitionX. Go on right side.
        // i.e. maxLeftY > minRightX
        low = partitionX + 1;
      }
    }
    return -1;
  }
}