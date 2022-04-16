// https://leetcode.com/problems/binary-tree-tilt/

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
  int tiltSum = 0;

  public int findTilt(TreeNode root) {
    postOrder(root);
    return tiltSum;
  }

  int postOrder(TreeNode node) {
    if (node == null) {
      return 0;
    }

    // Tilt sum is just the (sum of all nodes to left) - (sum of all nodes to right)
    int leftSum = postOrder(node.left);
    int rightSum = postOrder(node.right);

    int tilt = Math.abs(leftSum - rightSum);
    tiltSum += tilt;

    // Send back the total sum of this subtree.
    return node.val + leftSum + rightSum;
  }
}