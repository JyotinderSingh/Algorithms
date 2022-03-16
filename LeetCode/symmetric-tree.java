// https://leetcode.com/problems/symmetric-tree/
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

// Recursive Solution
class Solution {
  public boolean isSymmetric(TreeNode root) {
    return checkSymmetry(root.left, root.right);
  }

  public boolean checkSymmetry(TreeNode a, TreeNode b) {
    if (a == null && b == null)
      return true;
    if (a == null || b == null)
      return false;
    return a.val == b.val && checkSymmetry(a.left, b.right) && checkSymmetry(a.right, b.left);
  }
}

// Iterative solution