// https://leetcode.com/problems/odd-even-linked-list/

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
  public ListNode oddEvenList(ListNode head) {
    if (head == null)
      return head;

    ListNode odd = head, even = head.next, evenHead = head.next;

    // `even != null` rules out the list of only 1 node
    // `even.next != null` rules out the list of only 2 nodes
    while (even != null && even.next != null) {
      // Attach the next odd element.
      odd.next = odd.next.next;
      // Attach the next even element.
      even.next = even.next.next;

      // Move the pointers to the elements we just attached.
      odd = odd.next;
      even = even.next;
    }

    odd.next = evenHead;
    return head;
  }
}