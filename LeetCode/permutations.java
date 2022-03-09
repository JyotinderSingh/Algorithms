// https://leetcode.com/problems/permutations/

class Solution {
  public void backtrack(List<List<Integer>> result, List<Integer> tmp, int[] nums, Set<Integer> done) {
    if (tmp.size() == nums.length) {
      result.add(new ArrayList<>(tmp));
      return;
    }

    for (int i = 0; i < nums.length; ++i) {
      if (done.contains(nums[i])) {
        continue;
      }
      done.add(nums[i]);
      tmp.add(nums[i]);

      backtrack(result, tmp, nums, done);

      done.remove(nums[i]);
      tmp.remove(tmp.size() - 1);
    }
  }

  public List<List<Integer>> permute(int[] nums) {
    List<List<Integer>> result = new ArrayList();
    backtrack(result, new ArrayList<Integer>(), nums, new HashSet<>());
    return result;
  }
}