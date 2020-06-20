// https://leetcode.com/problems/minimum-depth-of-binary-tree/
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
    int minDepth(TreeNode *root)
    {
        if (!root)
        {
            // if this is a NULL pointer, return 0
            return 0;
        }
        if (!root->left || !root->right)
        {
            // if one of the children is NULL, then just consider the one which exists
            // we take a max, as the non existent one will anyway return 0
            // If BOTH turn out to be NULL, then we'll just get 0 + 1 = 1
            // that is, we'll just return the number of nodes in this subtree,
            // which is 1; this node itself
            return max(minDepth(root->left), minDepth(root->right)) + 1;
        }
        // if both children exist, just get the minimumdepth from either side
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};