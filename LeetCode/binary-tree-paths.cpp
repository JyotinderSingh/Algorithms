// https://leetcode.com/problems/binary-tree-paths/
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
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> res;
        if (!root)
        {
            return res;
        }
        helper(res, root, "");
        return res;
    }

    void helper(vector<string> &res, TreeNode *root, string cur_string)
    {
        if (!root->left && !root->right)
        {
            cur_string += to_string(root->val);
            res.push_back(cur_string);
            return;
        }
        cur_string += to_string(root->val);
        cur_string.append("->");
        if (root->left)
            helper(res, root->left, cur_string);
        if (root->right)
            helper(res, root->right, cur_string);
        return;
    }
};