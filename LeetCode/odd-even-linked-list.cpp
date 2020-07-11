// https://leetcode.com/problems/odd-even-linked-list/
// https://leetcode.com/problems/odd-even-linked-list/discuss/634620/easy-to-understand-solution-with-similar-variation-explained
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
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head)
        {
            return NULL;
        }

        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *evenHead = head->next;
        while (even != NULL && even->next != NULL)
        {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};

// Alt solution
class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head)
            return head;
        ListNode dummyHead(0);
        dummyHead.next = head;
        auto odd = head;
        auto even = head->next;
        auto evenHead = head->next;
        while (even && even->next)
        {
            odd->next = even->next;
            even->next = even->next->next;
            odd = odd->next;
            odd->next = evenHead;
            even = even->next;
        }
        return dummyHead.next;
    }
};

// FOR EVEN-ODD LL FOLLOW BELOW METHOD

class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head)
        {
            return NULL;
        }
        ListNode *odd = head;
        ListNode *oddHead = head;
        ListNode *even = head->next;
        ListNode *evenHead = even;

        while (odd and even and odd->next and even->next)
        {
            odd->next = even->next;
            odd = odd->next;

            // We need to add this extra check, otherwise we will have trouble connecting the end of the
            // even list to the head of the odd list (as even pointer could become NULL if the check is not there)
            if (odd->next)
            {
                even->next = odd->next;
                even = even->next;
            }
        }

        // connect the tail of the even list to the head of the odd list
        even->next = oddHead;

        // set the next pointer of the tail of the odd list to NULL
        odd->next = NULL;
        return evenHead;
    }
};