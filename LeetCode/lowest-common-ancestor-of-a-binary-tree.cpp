// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        // Base Case
        if (!root)
        {
            return NULL;
        }

        /*
        * If the root matches either of the search values, return this root
        * We don't need to care about repeating values because all the nodes
        * are given to be unique
        */
        if ((root->val == p->val) || (root->val == q->val))
        {
            return root;
        }

        /*
        * If the current node wasn't one of the nodes being searched for
        * search its children. 
        */
        TreeNode *leftSearchResult = lowestCommonAncestor(root->left, p, q);
        TreeNode *rightSearchResult = lowestCommonAncestor(root->right, p, q);

        // If left child isn't part of the search result, return the right
        if (!leftSearchResult)
        {
            return rightSearchResult;
        }

        // If the right child isn't part of the search result, return the left
        if (!rightSearchResult)
        {
            return leftSearchResult;
        }

        /*
        * If both the children returned non null values it means both the children have been found
        * and this is the LCA
        */
        return root;
    }
};