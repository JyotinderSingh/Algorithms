#include <iostream>
#include <memory>
#include "./LinkedListImplementation.h"
using namespace std;

// template <typename T>
// struct ListNode
// {
//     T data;
//     shared_ptr<ListNode<T>> next;
// };

// shared_ptr<ListNode<int>> SearchList(shared_ptr<ListNode<int>> L, int key)
// {
//     while (L && L->data != key)
//     {
//         L = L->next;
//     }
//     // if ke was not present in the list, L would have become null
//     return L;
// }

// // insert new node after specified node
// void InsertAfter(const shared_ptr<ListNode<int>> &node, const shared_ptr<ListNode<int>> &new_node)
// {
//     new_node->next = node->next;
//     node->next = new_node;
// }

// // Delete a node past this one. Assume node is not tail
// void DeleteAfter(const shared_ptr<ListNode<int>> &node)
// {
//     node->next = node->next->next;
// }


void AppendNode(shared_ptr<ListNode<int>> *node, shared_ptr<ListNode<int>> *tail)
{
    (*tail)->next = *node;
    *tail = *node; //updates tail
    *node = (*node)->next;
}

shared_ptr<ListNode<int>> MergeTwoSortedLists(shared_ptr<ListNode<int>> L1, shared_ptr<ListNode<int>> L2)
{
    // create a placeholder for the result
    shared_ptr<ListNode<int>> dummy_head(new ListNode<int>);
    auto tail = dummy_head;

    while (L1 && L2)
    {
        AppendNode(L1->data <= L2->data ? &L1 : &L2, &tail);
    }

    // Appends the remaining nodes of L1 or L2
    tail->next = L1 ? L1 : L2;
    return dummy_head->next;
}

// tester code
int main()
{
    cout<<"1";
    shared_ptr<ListNode<int>> n1(new ListNode<int>);
    n1->data = 1;

    shared_ptr<ListNode<int>> n2(new ListNode<int>);
    n2->data = 3;
    n2->next = nullptr;
    shared_ptr<ListNode<int>> n3(new ListNode<int>);
    n3->data = 5;
    n3->next = nullptr;
    n1->next = n2;
    n2->next = n3;

    shared_ptr<ListNode<int>> m1(new ListNode<int>);
    m1->data = 2;
    shared_ptr<ListNode<int>> m2(new ListNode<int>);
    m2->data = 4;
    m2->next = nullptr;
    // shared_ptr<ListNode<int>> m3(new ListNode<int>);
    // m3->data = 6;
    // m3->next = nullptr;
    m1->next = m2;
    // m2->next = m3;

    MergeTwoSortedLists(n1, n2);
    shared_ptr<ListNode<int>> temp = n1->data >= n2->data ? n2 : n1;
    while (temp)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
}