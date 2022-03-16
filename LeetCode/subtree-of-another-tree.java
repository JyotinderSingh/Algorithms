// https://leetcode.com/problems/subtree-of-another-tree/

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

 // Optimized method.
 
class Solution {
  public boolean isSubtree(TreeNode root, TreeNode subRoot) {
    List<TreeNode> nodeList = new ArrayList<>();

    // Add all nodes of root into nodeList which have height equal to that of
    // subRoot tree. We sent -1 as target depth to subRoot so that we never add
    // any of its nodes into the nodeList.
    getDepth(root, getDepth(subRoot, -1, nodeList), nodeList);

    // Now we have successfully reduced the problem space to check
    // only the nodes that can actually contain the subRoot tree.
    for (TreeNode node : nodeList) {
      if (isEqual(node, subRoot))
        return true;
    }
    return false;
  }

  // Returns the depth of the current node. If the depth is
  // equal to targetDepth it adds it to the nodes list.
  public int getDepth(TreeNode node, int targetHeight, List<TreeNode> nodeList) {
    if (node == null)
      return 0;

    int height = 1
        + Math.max(getDepth(node.left, targetHeight, nodeList), getDepth(node.right, targetHeight, nodeList));

    if (height == targetHeight) {
      nodeList.add(node);
    }

    return height;
  }

  public boolean isEqual(TreeNode a, TreeNode b) {
    if (a == null && b == null)
      return true;
    if (a == null || b == null) {
      return false;
    }
    if (a.val != b.val) {
      return false;
    }
    return isEqual(a.left, b.left) && isEqual(a.right, b.right);
  }
}

// Brute force.
class Solution {
  public boolean isSubtree(TreeNode root, TreeNode subRoot) {
    if (root == null && subRoot == null)
      return true;
    if (root == null || subRoot == null)
      return false;
    return isEqual(root, subRoot) || isSubtree(root.left, subRoot) || isSubtree(root.right, subRoot);
  }

  public boolean isEqual(TreeNode a, TreeNode b) {
    // pre-conditions
    if (a == null && b == null) {
      return true;
    }
    if (a == null || b == null) {
      return false;
    }

    // test for equality
    if (a.val != b.val) {
      return false;
    }

    // values are equal, check subtrees.
    return isEqual(a.left, b.left) && isEqual(a.right, b.right);
  }
}