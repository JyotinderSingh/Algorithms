// https://leetcode.com/problems/linked-list-cycle-ii/
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
    ListNode *detectCycle(ListNode *head)
    {
        if (!head || !head->next)
        {
            return NULL;
        }
        ListNode *slow = head;
        ListNode *fast = head;

        do
        {
            slow = slow->next;
            fast = fast->next->next;
        } while (fast && fast->next && slow != fast);
        if (slow != fast)
        {
            return NULL;
        }

        slow = head;
        while (fast != slow)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};