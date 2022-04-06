// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode(int x) { val = x; }
 * }
 */
class Solution {
  /**
   * Algorithm:
   * Query each node and ask it if its children contain either or both of the
   * targets.
   * In case they don't, return null.
   * In case they contain either one of them - return the said target.
   * In case they contain both - return the node itself.
   * Our logic is simple - if a node contributes to the answer, return it.
   * If it doesn't - return null.
   */
  public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
    // Base case.
    if (root == null)
      return null;

    // Check if this is one of the targets.
    if (root.val == p.val || root.val == q.val)
      return root;

    // The current node wasn't one of the nodes being searched for.
    // Query its children.
    TreeNode leftSearchResult = lowestCommonAncestor(root.left, p, q);
    TreeNode rightSearchResult = lowestCommonAncestor(root.right, p, q);

    // Below if conditions will return null if neither of the children are part
    // of the result.
    // If the left child isn't part of the search result, return the right child.
    if (leftSearchResult == null)
      return rightSearchResult;
    // If the right child isn't part of the search result, return the left child.
    if (rightSearchResult == null)
      return leftSearchResult;

    // If we got here it means that this node is the result. Return it.
    return root;
  }
}