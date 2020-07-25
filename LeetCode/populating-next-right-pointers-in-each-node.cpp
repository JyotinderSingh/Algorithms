// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

///////////////////////////////////////////////
////////// FASTER OPTIMIZED APPROACH //////////
/////////// O(N) Time + O(1) Space ////////////
///////////////////////////////////////////////

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        auto levelStart = root;
        while (levelStart != nullptr)
        {
            auto cur = levelStart;
            while (cur != nullptr)
            {
                // connect the left subtree
                if (cur->left)
                    cur->left->next = cur->right;
                if (cur->right && cur->next)
                    cur->right->next = cur->next->left;

                // move to the right portion of the (sub)tree to connect its subtrees
                cur = cur->next;
            }
            levelStart = levelStart->left;
        }
        return root;
    }
};

//////////////////////////////////////
///////// INTUITUVE APPROACH /////////
//////////////////////////////////////

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return root;
        root->next = nullptr;
        helper(root->left, root->right);
        return root;
    }

    void helper(Node *root, Node *right)
    {
        if (root == nullptr)
            return;
        root->next = right;
        helper(root ? root->left : nullptr, root ? root->right : nullptr);
        helper(root ? root->right : nullptr, right ? right->left : nullptr);
        helper(right ? right->left : nullptr, right ? right->right : nullptr);
        // helper(right ? right->right : nullptr, nullptr);
    }
};
