// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;

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
  public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
    List<Integer> result = new ArrayList<>();

    if (root == null)
      return result;

    // Keeps track of the parent of each node.
    HashMap<TreeNode, TreeNode> parents = new HashMap<>();
    // Keeps track of all the visited nodes.
    HashSet<TreeNode> visited = new HashSet<>();

    // populate the parents map.
    buildMap(root, null, parents);

    Queue<TreeNode> q = new ArrayDeque<>();
    q.offer(target);
    visited.add(target);

    int level = 0;

    // Loop to get the nodes at K'th level in the queue.
    while (!q.isEmpty()) {
      // We currently have nodes at level 'level' in the queue.
      // If level == k, break. The nodes in the queue are the result set.
      if (level == k)
        break;

      int nodesAtThisLevel = q.size();
      while (nodesAtThisLevel-- > 0) {
        TreeNode curr = q.poll();

        if (curr.left != null && !visited.contains(curr.left)) {
          q.offer(curr.left);
          visited.add(curr.left);
        }

        if (curr.right != null && !visited.contains(curr.right)) {
          q.offer(curr.right);
          visited.add(curr.right);
        }

        if (parents.get(curr) != null && !visited.contains(parents.get(curr))) {
          q.offer(parents.get(curr));
          visited.add(parents.get(curr));
        }
      }
      level++;
    }

    // We broke out of the loop when it contained the nodes for level k
    // (remember that we started at level 0, so AFTER k-1'th iteration you had the
    // required nodes in queue)
    while (!q.isEmpty()) {
      result.add(q.poll().val);
    }

    return result;
  }

  void buildMap(TreeNode node, TreeNode parent, HashMap<TreeNode, TreeNode> parents) {
    if (node == null)
      return;

    parents.put(node, parent);

    if (node.left != null)
      buildMap(node.left, node, parents);
    if (node.right != null)
      buildMap(node.right, node, parents);
  }
}