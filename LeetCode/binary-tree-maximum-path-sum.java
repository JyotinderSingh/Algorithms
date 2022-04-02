// https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
  int res = Integer.MIN_VALUE;

  public int maxPathSum(TreeNode root) {
    helper(root);
    return res;
  }

  public int helper(TreeNode root) {
    if (root == null) {
      return 0;
    }

    // l and r store maximum path sum going through left and
    // right child of root respectively
    int left = helper(root.left);
    int right = helper(root.right);

    // Max path for parent call of root. This path must
    // include at-most one child of root
    // this is the value that will be passed back to the parent node of this root.
    int singleMax = Math.max(Math.max(left, right) + root.val, root.val);

    // Max Top represents the sum when the Node under
    // consideration is the root of the maxsum path and no
    // ancestors of root are there in max sum path
    int maxTop = Math.max(left + right + root.val, singleMax);

    res = Math.max(res, maxTop);

    return singleMax;
  }
}