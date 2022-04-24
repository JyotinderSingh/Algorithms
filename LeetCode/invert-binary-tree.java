// https://leetcode.com/problems/invert-binary-tree/

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
class Solution {
  public TreeNode invertTree(TreeNode root) {
    if (root == null)
      return null;

    TreeNode invertedLeftSubTree = invertTree(root.left);
    TreeNode invertedRightSubTree = invertTree(root.right);

    root.left = invertedRightSubTree;
    root.right = invertedLeftSubTree;

    return root;
  }
}