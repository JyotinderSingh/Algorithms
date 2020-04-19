#include <iostream>
#include <memory>
#include "./LinkedListImplementation.h"
using namespace std;

ListNode<int>* MergeTwoSortedLists(ListNode<int>* L1, ListNode<int>* L2)
{
    // create a placeholder for the result
    ListNode<int>* dummy_head = L1;
    ListNode<int>* tail = dummy_head;

    while (L1 && L2)
    {
        if(L1->data < L2->data){
            tail->next = L1;
            L1 = L1->next;
        } else {
            tail->next = L2;
            L2 = L2->next;
        }
        tail = tail->next;
    }

    // Appends the remaining nodes of L1 or L2
    tail->next = L1 ? L1 : L2;
    return dummy_head->next;
}

// tester code
int main()
{   ListNode<int>* n3 = new ListNode<int>;
    n3->data = 5, n3->next = nullptr;

    ListNode<int>* n2 = new ListNode<int>;
    n2->data = 3, n2->next = n3;

    ListNode<int>* n1 = new ListNode<int>;
    n1->data = 1, n1->next = n2;

    ListNode<int>* m3 = new ListNode<int>;
    m3->data = 6, m3->next = nullptr;

    ListNode<int>* m2 = new ListNode<int>;
    m2->data = 5, m2->next = m3;

    ListNode<int>* m1 = new ListNode<int>;
    m1->data = 5, m1->next = m2;

    MergeTwoSortedLists(n1, n2);
    ListNode<int>* temp = n1->data <= m1->data ? m1 : n1;
    while (temp)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
}