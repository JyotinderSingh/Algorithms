// https://leetcode.com/problems/middle-of-the-linked-list/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        if (head == nullptr)
        {
            return head;
        }
        while (fast && fast->next)
        {
            slow = slow->next, fast = fast->next->next;
        }
        return slow;
    }
};