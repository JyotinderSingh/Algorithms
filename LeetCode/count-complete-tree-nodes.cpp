// https://leetcode.com/problems/count-complete-tree-nodes/

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
    int countNodes(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        int l = height(root->left);
        int r = height(root->right);

        // this means that the left sub tree will be full,
        // as a complete binary tree is filled from left to right
        if (l == r)
        {
            // (1 << l) includes the current root in the calculation as well
            return (1 << l) + countNodes(root->right);
        }
        else
        {
            // if l != r, then we know at the bottom most level, the left subtree
            // isn't completely filled, and we'll need to count the nodes manually
            // while the right subtree is completely filled, so we can simply use the forumla
            // which is 2^h - 1 (we don't subtract 1 here, as it helps include the the current
            // node in the calculation)
            return countNodes(root->left) + (1 << r);
        }
    }

    int height(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        // only check left as we know that we have a complete binary tree
        return 1 + height(root->left);
    }
};