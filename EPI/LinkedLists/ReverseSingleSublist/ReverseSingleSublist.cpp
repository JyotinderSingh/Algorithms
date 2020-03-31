#include <iostream>
#include <memory>
#include "../LinkedListImplementation.h"

shared_ptr<ListNode<int>> ReverseSublist(shared_ptr<ListNode<int>> L, int start, int finish)
{
    if (start == finish) // No need to reverse as start == finish
    {
        return L;
    }

    auto dummy_head = make_shared<ListNode<int>>(ListNode<int>{0, L});
    auto sublist_head = dummy_head;
    int k = 1; // index starts from 1
    while (k++ < start)
    {
        sublist_head = sublist_head->next;
    }

    auto sublist_iter = sublist_head->next;
    while (start++ < finish)
    {
        auto temp = sublist_iter->next;
        sublist_iter->next = temp->next;
        temp->next = sublist_head->next;
        sublist_head->next = temp;
    }
    return dummy_head->next;
}

int main()
{
    shared_ptr<ListNode<int>> n8(new ListNode<int>{8, nullptr});
    shared_ptr<ListNode<int>> n7(new ListNode<int>{7, n8});
    shared_ptr<ListNode<int>> n6(new ListNode<int>{6, n7});
    shared_ptr<ListNode<int>> n5(new ListNode<int>{5, n6});
    shared_ptr<ListNode<int>> n4(new ListNode<int>{4, n5});
    shared_ptr<ListNode<int>> n3(new ListNode<int>{3, n4});
    shared_ptr<ListNode<int>> n2(new ListNode<int>{2, n3});
    shared_ptr<ListNode<int>> n1(new ListNode<int>{1, n2});

    auto temp = n1;
    while (temp)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << endl;
    ReverseSublist(n1, 3, 6);

    temp = n1;
    while (temp)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
}