// https://leetcode.com/problems/add-two-numbers/
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(0);
        ListNode *iter = &dummy;
        int sum = 0, carry = 0;

        while (l1 || l2)
        {
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            sum = x + y + carry;
            carry = sum / 10;
            iter->next = new ListNode(sum % 10);
            iter = iter->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        if (carry)
        {
            iter->next = new ListNode(carry);
        }
        return dummy.next;
    }
};

///////////////////////////////////////
//// Same solution in different words//
///////////////////////////////////////

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(0);
        ListNode *iter = &dummy;

        int sum = 0, carry = 0;
        while (l1 || l2)
        {
            sum = 0;
            if (l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum / 10;
            sum = sum % 10;

            iter->next = new ListNode(sum);
            iter = iter->next;
        }

        if (carry != 0)
        {
            iter->next = new ListNode(carry);
        }

        return dummy.next;
    }
};