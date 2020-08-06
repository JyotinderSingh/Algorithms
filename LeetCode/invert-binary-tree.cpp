// https://leetcode.com/problems/invert-binary-tree/

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
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
            return root;
        auto left = invertTree(root->left);
        auto right = invertTree(root->right);

        root->left = right;
        root->right = left;

        return root;
    }
};

/////////////////////////////////////

class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        util(root);
        return root;
    }

    void util(TreeNode *root)
    {
        if (!root)
        {
            return;
        }
        auto temp = root->left;
        root->left = root->right;
        root->right = temp;
        util(root->left);
        util(root->right);
        return;
    }
};