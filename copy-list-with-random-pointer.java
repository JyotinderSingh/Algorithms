// https://leetcode.com/problems/copy-list-with-random-pointer/

// O(N) time and O(1) space


// O(N) time, O(N) space
class Solution {
  public Node copyRandomList(Node head) {
    // A mapping from original nodes to their clones.
    HashMap<Node, Node> cloneMap = new HashMap<>();

    Node curr = head;
    // First pass.
    while (curr != null) {
      cloneMap.put(curr, new Node(curr.val));
      curr = curr.next;
    }

    curr = head;
    while (curr != null) {
      cloneMap.get(curr).next = cloneMap.get(curr.next);
      cloneMap.get(curr).random = cloneMap.get(curr.random);
      curr = curr.next;
    }

    return cloneMap.get(head);
  }
}