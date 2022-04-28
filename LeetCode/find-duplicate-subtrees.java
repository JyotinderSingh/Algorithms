// https://leetcode.com/problems/find-duplicate-subtrees/

// O(N^2) time, O(N) space.
// Since strings are bring used, the concatenation takes O(n) time in each 
// recursive call taking overall complexity to O(n2).
// We perform postorder traversal, serializing and hashing the serials of subtrees 
// in the process. We can recognize a duplicate subtree by its serialization.

class Solution {
  public List<TreeNode> findDuplicateSubtrees(TreeNode root) {
    List<TreeNode> result = new LinkedList<>();
    postOrder(root, new HashMap<>(), result);
    return result;
  }

  public String postOrder(TreeNode curr, HashMap<String, Integer> map, List<TreeNode> result) {
    if (curr == null)
      return "#";
    String serial = curr.val + "," + postOrder(curr.left, map, result) + "," + postOrder(curr.right, map, result);
    map.put(serial, map.getOrDefault(serial, 0) + 1);
    if (map.get(serial) == 2)
      result.add(curr);
    return serial;
  }
}