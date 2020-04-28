// https://leetcode.com/problems/reverse-linked-list-ii/
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
    ListNode *reverseBetween(ListNode *head, int start, int end)
    {
        if (head == NULL)
        {
            return NULL;
        }
        if (start == end)
        {
            return head;
        }

        ListNode dummyHead(INT_MIN);
        dummyHead.next = head;

        ListNode *nodeBeforeReversedSublist = &dummyHead;
        int pos = 1;
        while (pos < start)
        {
            nodeBeforeReversedSublist = nodeBeforeReversedSublist->next;
            pos++;
        }

        ListNode *sublistWorkingPointer = nodeBeforeReversedSublist->next;
        while (start < end)
        {
            // 1.) Cut out of sublist
            ListNode *nodeComingToSublistFront = sublistWorkingPointer->next;
            sublistWorkingPointer->next = nodeComingToSublistFront->next;

            // 2.) Wire into sublist head
            nodeComingToSublistFront->next = nodeBeforeReversedSublist->next;
            nodeBeforeReversedSublist->next = nodeComingToSublistFront;

            start++;
        }
        return dummyHead.next;
    }
};