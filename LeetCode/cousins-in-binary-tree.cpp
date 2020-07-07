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
    int x_parent = -1, x_level = -1, y_parent = -1, y_level = -1;

public:
    bool isCousins(TreeNode *root, int x, int y)
    {
        findCousins(root, x, y, 0);
        return x_parent != y_parent && x_level == y_level;
    }

    void findCousins(TreeNode *root, int x, int y, int level)
    {
        if (root == nullptr || (x_parent != -1 && y_parent != -1))
        {
            return;
        }
        if ((root->left && root->left->val == x) || (root->right && root->right->val == x))
        {
            x_parent = root->val;
            x_level = level + 1;
            return;
        }
        if ((root->left && root->left->val == y) || (root->right && root->right->val == y))
        {
            y_parent = root->val;
            y_level = level + 1;
            return;
        }

        findCousins(root->left, x, y, level + 1);
        findCousins(root->right, x, y, level + 1);
    }
};