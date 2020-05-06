// https://leetcode.com/problems/intersection-of-two-linked-lists/
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == NULL || headB == NULL)
        {
            return NULL;
        }
        ListNode *a = headA;
        ListNode *b = headB;
        int i = 0;
        while (a != b)
        {
            a = a->next;
            b = b->next;
            if (a == NULL)
            {
                a = headB;
                i++;
            }
            if (b == NULL)
            {
                b = headA;
                i++;
            }
            if (i > 2)
            {
                return NULL;
            }
        }
        return a;
    }
};