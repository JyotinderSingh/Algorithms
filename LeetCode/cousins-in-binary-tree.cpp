// https://leetcode.com/problems/cousins-in-binary-tree/
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
    int xp = -1, yp = -1, xl, yl;

public:
    bool isCousins(TreeNode *root, int x, int y)
    {
        helper(root, x, y, 0);
        return xp != yp && xl == yl;
    }

    void helper(TreeNode *root, int x, int y, int level)
    {
        if (!root || (xp != -1 && yp != -1))
        {
            return;
        }
        if ((root->left && root->left->val == x) || (root->right && root->right->val == x))
        {
            xp = root->val;
            xl = level + 1;
            return;
        }
        if ((root->left && root->left->val == y) || (root->right && root->right->val == y))
        {
            yp = root->val;
            yl = level + 1;
            return;
        }
        helper(root->left, x, y, level + 1);
        helper(root->right, x, y, level + 1);
    }
};