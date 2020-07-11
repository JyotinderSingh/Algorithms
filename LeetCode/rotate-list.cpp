// https://leetcode.com/problems/rotate-list/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// Solution in EPI
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head)
            return head;

        // compute the length of the list and find the tail
        auto tail = head;
        int n = 1;
        while (tail->next)
        {
            n++, tail = tail->next;
        }
        k %= n;
        if (k == 0)
            return head;

        // make a cycle by connecting the tail to the head
        tail->next = head;
        auto new_tail = tail;

        int steps_to_new_tail = n - k;
        while (steps_to_new_tail--)
        {
            new_tail = new_tail->next;
        }

        // new_tail now points at the new tail, the next element is the new head
        auto new_head = new_tail->next;

        // finally close off the list
        new_tail->next = nullptr;

        return new_head;
    }
};