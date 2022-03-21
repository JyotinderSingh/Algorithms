// https://leetcode.com/problems/sliding-window-maximum/

class Solution {
  public int[] maxSlidingWindow(int[] nums, int k) {
    int n = nums.length;
    // if (n == 0 || k == 0) return new int[0];

    // n - k + 1 = number of windows.
    int[] result = new int[n - k + 1];

    // Deque to track index with max value in current sliding window.
    Deque<Integer> dq = new ArrayDeque<>();

    // iterate through the array.
    for (int i = 0; i < n; ++i) {
      // Remove the index that is out of bound.
      if (!dq.isEmpty() && dq.peekFirst() <= i - k) {
        dq.pollFirst();
      }

      /**
       * Check if the current element is max,
       * if yes, remove all elements in deque which
       * are smaller than it from the right.
       * We do this to maintain a monotonically decreasing queue.
       * So if the current element entering the window is greater
       * than the k - 1 elements before it, then it will be the
       * max element of this window, and for all future elements entering
       * its window (until it gets removed) till a greater element is found.
       */
      while (!dq.isEmpty() && nums[dq.peekLast()] < nums[i]) {
        dq.pollLast();
      }

      // Add the current element's index;
      dq.offerLast(i);

      // Add max of current window to the result.
      // this condition checks if we have covered enough elements
      // for at least 1 complete window.
      if (i >= k - 1) {
        result[i - k + 1] = nums[dq.peekFirst()];
      }
    }
    return result;
  }
}