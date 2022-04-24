// https://leetcode.com/problems/jump-game/

class Solution {
  public boolean canJump(int[] nums) {
    int furthest = 0;

    for (int i = 0; i < nums.length && i <= furthest; ++i) {
      furthest = Math.max(furthest, i + nums[i]);
    }

    return furthest >= nums.length - 1 ? true : false;
  }
}