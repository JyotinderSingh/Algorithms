// https://leetcode.com/problems/binary-tree-level-order-traversal/
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (!root)
        {
            return res;
        }
        int h = height(root);
        vector<int> curr_level;
        for (int i = 1; i <= h; ++i)
        {
            printGivenLevel(root, i, curr_level);
            res.push_back(curr_level);
            curr_level.clear();
        }
        return res;
    }

    void printGivenLevel(TreeNode *root, int level, vector<int> &curr_level)
    {
        if (!root)
        {
            return;
        }
        if (level == 1)
        {
            curr_level.push_back(root->val);
        }
        printGivenLevel(root->left, level - 1, curr_level);
        printGivenLevel(root->right, level - 1, curr_level);
    }

    int height(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        return 1 + max(height(root->left), height(root->right));
    }
};