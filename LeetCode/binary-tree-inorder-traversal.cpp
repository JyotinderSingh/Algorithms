// https://leetcode.com/problems/binary-tree-inorder-traversal/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    void helper(TreeNode *root, vector<int> &res)
    {
        if (root == NULL)
        {
            return;
        }
        helper(root->left, res);
        res.push_back(root->val);
        helper(root->right, res);
        return;
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        helper(root, res);
        return res;
    }
};