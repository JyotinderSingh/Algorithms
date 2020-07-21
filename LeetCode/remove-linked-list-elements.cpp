// https://leetcode.com/problems/remove-linked-list-elements/
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
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode dummy(0, head);
        ListNode *tail = &dummy;
        while (tail->next)
        {
            if (tail->next->val == val)
            {
                tail->next = tail->next->next;
            }
            else
            {
                tail = tail->next;
            }
        }
        return dummy.next;
    }
};