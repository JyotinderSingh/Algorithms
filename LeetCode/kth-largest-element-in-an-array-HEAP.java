// https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
  public int findKthLargest(int[] nums, int k) {
    // MIN HEAP: Smallest element first.
    PriorityQueue<Integer> heap = new PriorityQueue<>(nums.length, (n1, n2) -> n1 - n2);

    // Keep K largest elements in heap.
    // We maintain a heap of size K - and since this is a min heap
    // the order of elements will be from smallest to largest.
    // With the first element automatically being the K'th largest
    // element (largest element seen so far would be the last element).
    // Time complexity: O(N * log(K))
    for (int n : nums) {
      heap.add(n);
      if (heap.size() > k) {
        heap.poll();
      }
    }

    return heap.poll();
  }
}