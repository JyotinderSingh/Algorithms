// https://leetcode.com/problems/validate-binary-search-tree/
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
    bool isValidBST(TreeNode *root, TreeNode *lowerBound = nullptr, TreeNode *upperBound = nullptr)
    {
        if (!root)
            return true;

        if (lowerBound && root->val <= lowerBound->val)
            return false;

        if (upperBound && root->val >= upperBound->val)
            return false;

        return isValidBST(root->left, lowerBound, root) && isValidBST(root->right, root, upperBound);
    }
};