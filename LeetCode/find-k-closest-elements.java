// https://leetcode.com/problems/find-k-closest-elements/

/**
 * 
 * Time Complexity: O(logn), Space Complexity: O(1)
 */
class Solution {
  public List<Integer> findClosestElements(int[] arr, int k, int x) {
    // Start with a window of length k that starts at index 0.
    int left = 0, right = arr.length - k;

    // Binary Search.
    while (left < right) {
      // find mid.
      int mid = left + (right - left) / 2;

      /**
       * We want to find the left bound of the window.
       * We basically want to consider a window of size k starting at index mid.
       * We have a competition between the positions mid and (mid + k) on
       * which one of them will be included in the window.
       * If the distance between x and the element at index mid is less than
       * the distance between x and the element at index (mid + k), then we
       * want to reduce the right bound of the window. This is because we want
       * only k elements in our set, and (mid + k) and any elements to it's right
       * are further away from x that the one at mid.
       * Now we have moved right to mid. We now search for a lower left bound
       * of the window.
       * So we check the mid element and the element at mid + k. If the distance
       * between x and the element at index mid is more than the distance
       * between x and the element at index (mid + k), then we want to increase
       * the left bound of the window. This is because we want to include the
       * element at mid + k in the window. So we move left to mid + 1.
       * Vice versa and so on.
       */
      if (x - arr[mid] > arr[mid + k] - x) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    List<Integer> result = new ArrayList<>(k);
    for (int i = left; i < left + k; ++i) {
      result.add(arr[i]);
    }

    return result;
  }
}

/**
 * check every number in arr for its distance from x and sort the numbers by
 * this criterion. Then, the answer will be the first k elements of our new
 * sorted array.
 * - reate a new array sortedArr, that is arr sorted with a custom comparator.
 * The comparator should be abs(x - num) for each num in arr.
 * Sorting the array in ascending order means that the first k elements will
 * be the k closest elements to x.
 * - We also have to sort the "sorted" array, since the problem wants our output
 * in ascending order. Return the first k elements of sortedArr, sorted by
 * value, in ascending order.
 * 
 * Time complexity: O(nlogn + klogk)
 * Space complexity: O(n)
 */
class Solution {

  public List<Integer> findClosestElements(int[] arr, int k, int x) {
    List<Integer> sortedArr = new ArrayList<>();
    for (int num : arr) {
      sortedArr.add(num);
    }

    // sort using custom comparator.
    Collections.sort(sortedArr, (num1, num2) -> Math.abs(num1 - x) - Math.abs(num2 - x));

    sortedArr = sortedArr.subList(0, k);

    Collections.sort(sortedArr);
    return sortedArr;
  }
}