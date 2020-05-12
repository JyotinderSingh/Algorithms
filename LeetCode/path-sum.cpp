// https://leetcode.com/problems/path-sum/
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
    bool hasPathSum(TreeNode *root, int sum)
    {
        return dfs(root, 0, sum);
    }

    bool dfs(TreeNode *root, int currSum, int sum)
    {
        if (!root)
        {
            return false;
        }
        currSum += root->val;
        if (currSum == sum && !root->left && !root->right)
        {
            return true;
        }
        return dfs(root->left, currSum, sum) || dfs(root->right, currSum, sum);
    }
};