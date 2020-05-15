// https://leetcode.com/problems/balanced-binary-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }

        if (abs(height(root->left) - height(root->right)) > 1)
        {
            return false;
        }

        return isBalanced(root->left) and isBalanced(root->right);
    }

    int height(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        return max(height(root->left), height(root->right)) + 1;
    }
};

// More sophisticated (but somehow slower??) solution
// that avoids recalculation of heights for each node

class BalanceStatusWithHeight
{
public:
    bool isBalanced;
    int height;

    BalanceStatusWithHeight(bool isBalanced, int height)
    {
        this->isBalanced = isBalanced;
        this->height = height;
    }
};

class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        return checkBalance(root).isBalanced;
    }

    BalanceStatusWithHeight checkBalance(TreeNode *root)
    {
        if (!root)
        {
            return BalanceStatusWithHeight(true, 0);
        }

        auto l = checkBalance(root->left);
        auto r = checkBalance(root->right);

        if (!l.isBalanced)
        {
            return l;
        }

        if (!r.isBalanced)
        {
            return r;
        }

        bool balanceStatus = abs(l.height - r.height) > 1 ? false : true;
        int height = max(l.height, r.height) + 1;

        return BalanceStatusWithHeight(balanceStatus, height);
    }
};