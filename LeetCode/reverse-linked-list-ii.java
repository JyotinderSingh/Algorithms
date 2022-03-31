// https://leetcode.com/problems/reverse-linked-list-ii/

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
  public ListNode reverseBetween(ListNode head, int start, int end) {
    // Edge case.
    if (head == null || start == end)
      return head;

    // Pad a dummy head to the start of the list
    ListNode dummyHead = new ListNode(-1);
    dummyHead.next = head;

    ListNode nodeBeforeReversedSublist = dummyHead;
    int pos = 1;
    while (pos < start) {
      nodeBeforeReversedSublist = nodeBeforeReversedSublist.next;
      pos++;
    }

    ListNode sublistWorkingPtr = nodeBeforeReversedSublist.next;
    while (start < end) {
      // 1.) Cut out of sublist
      ListNode nodeComingToSublistFront = sublistWorkingPtr.next;
      sublistWorkingPtr.next = nodeComingToSublistFront.next;

      // 2.) Wire into sublist head
      nodeComingToSublistFront.next = nodeBeforeReversedSublist.next;
      nodeBeforeReversedSublist.next = nodeComingToSublistFront;

      start++;
    }

    return dummyHead.next;
  }
}