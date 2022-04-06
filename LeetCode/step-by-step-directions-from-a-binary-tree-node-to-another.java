// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/

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
  public String getDirections(TreeNode root, int startValue, int destValue) {
    // find lowest common ancestor, this is where we start building the path.
    TreeNode ancestor = getLCA(root, startValue, destValue);

    StringBuilder ancestorToStart = new StringBuilder();
    StringBuilder ancestorToDest = new StringBuilder();

    // Build path strings to the start and dest values.
    traverse(ancestor, startValue, ancestorToStart);
    traverse(ancestor, destValue, ancestorToDest);

    // The path from start to ancestor will just be a series of "UP"s
    String s = "U";
    s = s.repeat(ancestorToStart.length());

    // Append the path to the dest.
    return s + ancestorToDest.toString();

  }

  boolean traverse(TreeNode node, int dest, StringBuilder s) {
    // Base case, if we reached null it means we didn't find the dest val.
    if (node == null)
      return false;

    // We are at the destination node.
    if (node.val == dest)
      return true;

    // look for destination in children.
    // We first look into the left subpath, and reflect the same in our string.
    s.append('L');
    // if we find dest in the left subpath, return true.
    if (traverse(node.left, dest, s))
      return true;
    // we didn't find the dest in the left subpath, so remove that from
    // the string and replace it with 'R' since we are going to explore
    // right subpath.
    s.setCharAt(s.length() - 1, 'R');
    if (traverse(node.right, dest, s))
      return true;
    // we did not find the character in any sub child, remove the character
    // denoting the right sub path from the string that we just added and return
    // false.
    s.deleteCharAt(s.length() - 1);
    return false;
  }

  TreeNode getLCA(TreeNode node, int startValue, int destValue) {
    if (node == null)
      return null;

    if (node.val == startValue || node.val == destValue)
      return node;

    TreeNode leftSearchResult = getLCA(node.left, startValue, destValue);
    TreeNode rightSearchResult = getLCA(node.right, startValue, destValue);

    if (leftSearchResult != null && rightSearchResult != null)
      return node;

    return leftSearchResult == null ? rightSearchResult : leftSearchResult;
  }
}