// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
import java.util.LinkedList;

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
  public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
    List<List<Integer>> result = new ArrayList<>();
    Queue<TreeNode> q = new LinkedList<>();

    if (root == null)
      return result;

    boolean isOrderLeft = true;
    q.offer(root);

    while (!q.isEmpty()) {
      // Clear the currLevel list for new level.
      LinkedList<Integer> currLevel = new LinkedList<>();
      int size = q.size();

      while (size-- > 0) {
        TreeNode curr = q.poll();

        if (curr.left != null)
          q.add(curr.left);
        if (curr.right != null)
          q.add(curr.right);

        if (isOrderLeft) {
          currLevel.addLast(curr.val);
        } else {
          currLevel.addFirst(curr.val);
        }
      }
      result.add(currLevel);
      isOrderLeft = !isOrderLeft;
    }

    return result;
  }
}