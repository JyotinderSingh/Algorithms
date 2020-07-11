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
        ListNode dummy(0, head);

        /*
        * fast is initialized at the actual head, so that let's say n = 1
        * then after 1 iteration of the following while loop, fast and slow
        * will have 1 node between them
        * then once the second while loop starts, and ends when fast == nullptr
        * it would mean that slow is at the second last element of the list at that time
        * because fast and slow always maintain a difference of 1 node between them.
        * So now we can simply modify the next ptr of the slow ptr to delete the target node.
        */

        ListNode *slow = &dummy, *fast = dummy.next;
        while (n--)
            fast = fast->next;
        while (fast)
            slow = slow->next, fast = fast->next;
        slow->next = slow->next->next;
        return dummy.next;
    }
};

//////////////////////////////////////////////////////

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