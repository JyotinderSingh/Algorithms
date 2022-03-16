// https://leetcode.com/problems/shuffle-an-array/

class Solution {
  int[] nums;

  public Solution(int[] nums) {
    this.nums = nums;
  }

  public int[] reset() {
    return nums;
  }

  public int[] shuffle() {
    int[] shuff = new int[nums.length];
    System.arraycopy(nums, 0, shuff, 0, nums.length);
    for (int i = 0; i < nums.length; ++i) {
      int j = ThreadLocalRandom.current().nextInt(0, nums.length);
      swap(shuff, i, j);
    }
    return shuff;
  }

  public void swap(int[] arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int[] param_1 = obj.reset();
 * int[] param_2 = obj.shuffle();
 */