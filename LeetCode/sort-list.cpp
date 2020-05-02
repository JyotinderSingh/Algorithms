// https://leetcode.com/problems/sort-list/
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
    ListNode *sortList(ListNode *head)
    {

        // Base case, an empty list or a single item list
        // This is a sorted list, hence we just return the list
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        // Abstracting out finding the middle node
        ListNode *mid = getMiddleAndSplitInHalf(head);

        // Sort the left, sort the right.
        // This is recursive splitting and handing responsibility off
        ListNode *leftHalf = sortList(head);
        ListNode *rightHalf = sortList(mid);

        // Merge the sorted left half and the right half
        return merge(leftHalf, rightHalf);
    }

    ListNode *merge(ListNode *l1Pointer, ListNode *l2Pointer)
    {
        ListNode dummyHead(0);
        ListNode *endOfSortedList = &dummyHead;

        // While neither list has been exhausted keep doing comparisons and rewirings
        while (l1Pointer != NULL && l2Pointer != NULL)
        {
            if (l1Pointer->val < l2Pointer->val)
            {
                // Where l1 points gets the placement
                endOfSortedList->next = l1Pointer;
                l1Pointer = l1Pointer->next;
            }
            else
            {
                // Where l2 points gets the placement
                endOfSortedList->next = l2Pointer;
                l2Pointer = l2Pointer->next;
            }
            endOfSortedList = endOfSortedList->next;
        }

        // If we exhaust one list, just tack the other to the end of the sorted list
        if (l1Pointer != NULL)
        {
            endOfSortedList->next = l1Pointer;
        }
        if (l2Pointer != NULL)
        {
            endOfSortedList->next = l2Pointer;
        }

        // The head of the merged list is the ->next of the dummy head, the dummy head
        // helped us protect against the empty state the list was in to start
        return dummyHead.next;
    }

    ListNode *getMiddleAndSplitInHalf(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *slow = head;
        ListNode *fast = head;

        /*
        * Slow pointer, 1 hop per iteration
        * Fast pointer, 2 hops per iteration
        * When 'fast' reaches the last element or runs over the list
        * the 'slow' will point to the middle of the list
        */
        while (fast != NULL && fast->next != NULL)
        {
            // Keep prev 1 behind where slow will be. We want this for later
            prev = slow;

            // Move the slow and fast pointers
            slow = slow->next;
            fast = fast->next->next;
        }

        /*
        * Cut off the end of the first half list so it is no longer connected
        * in memory to the right half list head
        * We kept track of prev to be able to do this cutoff
        */
        prev->next = NULL;

        // 'slow' sits at the middle of the list
        return slow;
    }
};
