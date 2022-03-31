// https://leetcode.com/problems/reverse-linked-list/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode() {}
 * ListNode(int val) { this.val = val; }
 * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
  public ListNode reverseList(ListNode head) {
    ListNode curr = head;
    ListNode prev = null;
    while (curr != null) {
      // Save the next pointer, since now we are going to rewire the
      // current node's next pointer to point to the previous node.
      ListNode next = curr.next;
      // rewiring
      curr.next = prev;
      // make sure we save a reference to the curr pointer before we move forward.
      prev = curr;
      // move to the next node.
      curr = next;
    }

    return prev;
  }
}