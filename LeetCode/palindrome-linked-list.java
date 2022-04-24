// https://leetcode.com/problems/palindrome-linked-list/

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
  public boolean isPalindrome(ListNode head) {
    ListNode slow = head, fast = head;

    while (fast != null && fast.next != null) {
      fast = fast.next.next;
      slow = slow.next;
    }

    // 'slow' is at the middle element of the linkedlist now
    // we want to reverse the list from this middle.
    slow = reverseList(slow);

    // start comparing elements.
    fast = head;
    while (slow != null) {
      if (slow.val != fast.val) {
        return false;
      }
      slow = slow.next;
      fast = fast.next;
    }

    return true;
  }

  ListNode reverseList(ListNode node) {
    ListNode prev = null, next = null;
    while (node != null) {
      // save the next pointer.
      next = node.next;
      // reverse the next pointer for current node.
      node.next = prev;

      // update prev to current node.
      prev = node;
      // move current node to next node.
      node = next;
    }
    return prev;
  }
}