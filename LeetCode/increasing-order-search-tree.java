// https://leetcode.com/problems/increasing-order-search-tree/

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
  TreeNode cur;

  public TreeNode increasingBST(TreeNode root) {
    TreeNode head = new TreeNode(Integer.MIN_VALUE);
    cur = head;
    helper(root);
    return head.right;
  }

  private void inorder(TreeNode node) {
    if (node == null)
      return;

    // recurse in in-order fashion. Process left child first.
    inorder(node.left);

    // Process the node itself.
    // Attach the node to the working ptr of resulting tree.
    cur.right = node;
    // Shift the working ptr.
    cur = node;
    // we have already processed the left child (in order traversal)
    node.left = null;

    // move to right child.
    inorder(node.right);
  }
}