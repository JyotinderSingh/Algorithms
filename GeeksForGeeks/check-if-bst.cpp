// https://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to 
   left child and a pointer to right child */
struct Node
{
    int data;
    struct Node *left, *right;
};

bool isBST(Node *root, Node *l = NULL, Node *r = NULL)
{
    if (root == NULL)
    {
        return true;
    }

    if (l != NULL && root->data <= l->data)
    {
        return false;
    }

    if (r != NULL && root->data >= r->data)
    {
        return false;
    }

    return isBST(root->left, l, root) && isBST(root->right, root, r);
}

/* Helper function that allocates a new node with the 
   given data and NULL left and right pointers. */
struct Node *newNode(int data)
{
    struct Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

/* Driver program to test above functions*/
int main()
{
    struct Node *root = newNode(3);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(4);

    if (isBST(root, NULL, NULL))
        cout << "Is BST";
    else
        cout << "Not a BST";

    return 0;
}