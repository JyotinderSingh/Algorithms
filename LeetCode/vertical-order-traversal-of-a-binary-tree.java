// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

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

// 'Priority Queue only' solution
class Solution {
  // Data Structure to hold coordinate information for each node.
  class Point {
    int x;
    int y;
    int val;

    public Point(int val, int x, int y) {
      this.val = val;
      this.x = x;
      this.y = y;
    }
  }

  public List<List<Integer>> verticalTraversal(TreeNode root) {
    List<List<Integer>> result = new ArrayList<>();

    // PQ which sorts nodes in ascending order of x and y coords (acc to condition
    // in question).
    PriorityQueue<Point> pq = new PriorityQueue<>(1001, (p1, p2) -> {
      if (p1.x < p2.x)
        return -1;
      if (p1.x > p2.x)
        return 1;
      if (p1.y < p2.y)
        return -1;
      if (p1.y > p2.y)
        return 1;
      return p1.val - p2.val;
    });

    // Add all the nodes to the PQ with their coordinates.
    verticalTraversalHelper(root, 0, 0, pq);

    // variable to hold previously processed point.
    Point prev = null;
    // list to hold all the nodes in the current column.
    List<Integer> currLevel = new ArrayList<>();
    while (!pq.isEmpty()) {
      Point p = pq.poll();

      // check if have entered a new column.
      if (prev != null && p.x != prev.x) {
        // We encountered a new level.
        // So flush the current level to the result array.
        result.add(currLevel);
        // reset currLevel
        currLevel = new ArrayList<>();
      }

      // add the node to the current level being processed.
      currLevel.add(p.val);
      prev = p;
    }

    // Add the last level
    result.add(currLevel);
    return result;
  }

  void verticalTraversalHelper(TreeNode node, int x, int y, PriorityQueue<Point> pq) {
    if (node == null)
      return;
    pq.add(new Point(node.val, x, y));
    verticalTraversalHelper(node.left, x - 1, y + 1, pq);
    verticalTraversalHelper(node.right, x + 1, y + 1, pq);
  }
}

// Map + Priority Queue SOLUTION.
class Solution {
  public List<List<Integer>> verticalTraversal(TreeNode root) {
    // Grid to hold our coordinate mappings.
    // We use TreeMap to enforce an order based on our comparator.
    // We pass the comparator to sort the values based on x coords from lowest to
    // highest.
    // We store actual node values in PQ since in case of multiple nodes with same
    // (x,y) coords, we need to store them in ascending order.
    TreeMap<Integer, TreeMap<Integer, PriorityQueue<Integer>>> grid = new TreeMap<>(Comparator.comparingInt(a -> a));

    // build the grid.
    traverse(root, 0, 0, grid);

    List<List<Integer>> result = new ArrayList<>();

    // traverse through x coords (sorted in asc order due to comparator)
    for (TreeMap<Integer, PriorityQueue<Integer>> ys : grid.values()) {
      result.add(new ArrayList<>());
      // traverse through the PQ present at coords (x,y)
      for (PriorityQueue<Integer> nodes : ys.values()) {
        while (!nodes.isEmpty()) {
          result.get(result.size() - 1).add(nodes.poll());
        }
      }
    }
    return result;
  }

  void traverse(TreeNode node, int x, int y, TreeMap<Integer, TreeMap<Integer, PriorityQueue<Integer>>> grid) {
    if (node == null)
      return;

    if (!grid.containsKey(x)) {
      // We pas the comparator to sort the values based on y coords from lowest to
      // highest.
      grid.put(x, new TreeMap<>(Comparator.comparingInt(a -> a)));
    }
    if (!grid.get(x).containsKey(y)) {
      grid.get(x).put(y, new PriorityQueue<>());
    }

    grid.get(x).get(y).offer(node.val);

    traverse(node.left, x - 1, y + 1, grid);
    traverse(node.right, x + 1, y + 1, grid);
  }
}