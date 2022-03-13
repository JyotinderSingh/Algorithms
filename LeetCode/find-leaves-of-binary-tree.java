import java.util.ArrayList;
import java.util.List;

// https://leetcode.com/problems/find-leaves-of-binary-tree/
/**
 * Given the root of a binary tree, collect a tree's nodes as if you were doing this:

- Collect all the leaf nodes.
- Remove all the leaf nodes.
- Repeat until the tree is empty.

Input: root = [1,2,3,4,5]
Output: [[4,5,3],[2],[1]]
Explanation:
[[3,5,4],[2],[1]] and [[3,4,5],[2],[1]] are also considered correct answers since per each level it does not matter the order on which elements are returned.
 */

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */

// Finding height (100% time, 50% space)
class Solution {
  public int height(TreeNode node, List<List<Integer>> res) {
    // return -1 in case of null node (helps make the height of the leaves as 0)
    if (node == null)
      return -1;

    // find the level of the current node
    int level = 1 + Math.max(height(node.left, res), height(node.right, res));

    // make sure a slot exists in the result array for this level.
    if (res.size() < level + 1)
      res.add(new ArrayList<>());
    // add the node's value to its level's corresponding slot in the result array.
    res.get(level).add(node.val);

    return level;
  }

  public List<List<Integer>> findLeaves(TreeNode root) {
    List<List<Integer>> result = new ArrayList<>();
    height(root, result);
    return result;
  }
}