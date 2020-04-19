#include <iostream>
#include <memory>
using namespace std;

template <typename T>
struct ListNode
{
    T data;
    ListNode<T> *next;
};

ListNode<int> *SearchList(ListNode<int> *L, int key)
{
    while (L && L->data != key)
    {
        L = L->next;
    }
    // if ke was not present in the list, L would have become null
    return L;
}

// insert new node after specified node
void InsertAfter(ListNode<int> *node, ListNode<int> *new_node)
{
    new_node->next = node->next;
    node->next = new_node;
}

// Delete a node past this one. Assume node is not tail
void DeleteAfter(ListNode<int> * node)
{
    node->next = node->next->next;
}
