// https://leetcode.com/problems/random-pick-with-weight/

// Binary Search on Prefix Sums array
class Solution {
  private int[] prefixSums;
  private int totalSum;

  public Solution(int[] w) {
    this.prefixSums = new int[w.length];

    int prefixSum = 0;
    for (int i = 0; i < w.length; ++i) {
      prefixSum += w[i];
      this.prefixSums[i] = prefixSum;
    }
    this.totalSum = prefixSum;
  }

  public int pickIndex() {
    double target = this.totalSum * Math.random();

    // run a binary search to find the target zone
    int low = 0, high = this.prefixSums.length;
    while (low < high) {
      // better to avoid the overflow
      int mid = low + (high - low) / 2;
      if (target > this.prefixSums[mid])
        low = mid + 1;
      else
        high = mid;
    }
    return low;
  }
}

// Linear Search Solution.
class Solution {
  private int[] prefixSums;
  private int totalSum;

  public Solution(int[] w) {
    this.prefixSums = new int[w.length];

    int prefixSum = 0;
    for (int i = 0; i < w.length; ++i) {
      prefixSum += w[i];
      this.prefixSums[i] = prefixSum;
    }
    this.totalSum = prefixSum;
  }

  public int pickIndex() {
    double target = this.totalSum * Math.random();
    int i = 0;
    // run a linear search to find the target zone
    for (; i < this.prefixSums.length; ++i) {
      if (target < this.prefixSums[i])
        return i;
    }
    // to have a return statement, though this should never happen.
    return -1;
  }
}
