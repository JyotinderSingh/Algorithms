// https://leetcode.com/problems/partition-list/
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
    ListNode *partition(ListNode *head, int x)
    {

        // Maintain 2 lists, one with elements smaller than the pivot,
        // one with elements greater than equal to pivot
        ListNode smaller(0), greaterEqual(0);
        auto *smallerIter = &smaller, *greaterEqualIter = &greaterEqual;
        while (head)
        {
            if (head->val < x)
            {
                smallerIter->next = head;
                smallerIter = smallerIter->next;
            }
            else
            {
                greaterEqualIter->next = head;
                greaterEqualIter = greaterEqualIter->next;
            }
            head = head->next;
        }

        // connect the two lists
        greaterEqualIter->next = nullptr;
        smallerIter->next = greaterEqual.next;

        return smaller.next;
    }
};