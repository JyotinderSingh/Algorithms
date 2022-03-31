// https://leetcode.com/problems/clone-graph/

/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

// DFS

class Solution {
  HashMap<Node, Node> cloneMap = new HashMap<>();

  public Node cloneGraph(Node node) {
    if (node == null) {
      return node;
    }

    // Check if we have already cloned this node,
    // if yes then directly return the clone.
    if (cloneMap.containsKey(node)) {
      return cloneMap.get(node);
    }

    // clone the node
    Node cloneNode = new Node(node.val, new ArrayList<>());
    cloneMap.put(node, cloneNode);

    // Iterate through the neighbors of the node.
    for (Node neighbor : node.neighbors) {
      // Clone each neighbor and add it to the neighbour list.
      cloneNode.neighbors.add(cloneGraph(neighbor));
    }

    return cloneNode;
  }
}

// BFS

/*
 * // Definition for a Node.
 * class Node {
 * public int val;
 * public List<Node> neighbors;
 * public Node() {
 * val = 0;
 * neighbors = new ArrayList<Node>();
 * }
 * public Node(int _val) {
 * val = _val;
 * neighbors = new ArrayList<Node>();
 * }
 * public Node(int _val, ArrayList<Node> _neighbors) {
 * val = _val;
 * neighbors = _neighbors;
 * }
 * }
 */

class Solution {
  public Node cloneGraph(Node node) {
    if (node == null)
      return node;

    Queue<Node> queue = new ArrayDeque<>();
    HashMap<Node, Node> cloneMap = new HashMap<>();

    queue.offer(node);
    cloneMap.put(node, new Node(node.val, new ArrayList<>()));

    while (!queue.isEmpty()) {
      // pop a node from the front of the queue.
      Node curr = queue.poll();

      // iterate over this node's neighbors.
      for (Node neighbor : curr.neighbors) {
        // if we haven't yet cloned this neighbour
        if (!cloneMap.containsKey(neighbor)) {
          // clone the neighbor and put in the cloneMap.
          cloneMap.put(neighbor, new Node(neighbor.val, new ArrayList<>()));

          // Add it to the queue since we need to populate its neighbor list.
          queue.add(neighbor);
        }

        // Add the clone of the neighbour to the neighbors of the clone node "n".
        cloneMap.get(curr).neighbors.add(cloneMap.get(neighbor));
      }
    }

    // Return the clone of the node from the cloneMap.
    return cloneMap.get(node);
  }
}