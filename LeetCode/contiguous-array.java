// https://leetcode.com/problems/contiguous-array/
// https://leetcode.com/problems/contiguous-array/discuss/1743431/A-highly-detailed-EXPLANATION-ever-exists-JavaC%2B%2B

class Solution {
  public int findMaxLength(int[] nums) {
    Map<Integer, Integer> map = new HashMap<>();
    int maxlen = 0, gain = 0;

    // Initially we start at -1 index (hypothetically)
    // and we are at a stable state where our gain is 0.
    // This -1 basically helps us calculate length of contiguous
    // subarray when we get to 0 gain anywhere in the nums array.
    map.put(0, -1);

    for (int i = 0; i < nums.length; ++i) {
      gain += nums[i] == 0 ? -1 : 1;

      // If we had encountered this gain before
      // we calculate length of sub array.
      if (map.containsKey(gain)) {
        maxlen = Math.max(maxlen, i - map.get(gain));
      } else {
        // We save the first instance where we get this gain.
        map.put(gain, i);
      }
    }

    return maxlen;
  }
}