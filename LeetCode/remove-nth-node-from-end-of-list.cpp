// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *fast = &dummy;
        ListNode *prev = &dummy;

        // Advances fast pointer so that the gap between first and second is n nodes apart
        // Final postition:
        // prev -> <target> ... <n - 1 nodes> -> fast (NULL)
        for (int i = 1; i <= n + 1; ++i)
        {
            fast = fast->next;
        }

        // Move fast to the end, maintaining the gap
        while (fast)
        {
            prev = prev->next;
            fast = fast->next;
        }
        
        auto temp = prev->next;
        prev->next = prev->next->next;
        delete (temp);

        return dummy.next;
    }
};