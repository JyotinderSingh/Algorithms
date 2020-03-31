#include <iostream>
#include <memory>
using namespace std;

template <typename T>
struct ListNode
{
    T data;
    shared_ptr<ListNode<T>> next;
};

shared_ptr<ListNode<int>> SearchList(shared_ptr<ListNode<int>> L, int key)
{
    while (L && L->data != key)
    {
        L = L->next;
    }
    // if ke was not present in the list, L would have become null
    return L;
}

// insert new node after specified node
void InsertAfter(const shared_ptr<ListNode<int>> &node, const shared_ptr<ListNode<int>> &new_node)
{
    new_node->next = node->next;
    node->next = new_node;
}

// Delete a node past this one. Assume node is not tail
void DeleteAfter(const shared_ptr<ListNode<int>> &node)
{
    node->next = node->next->next;
}
