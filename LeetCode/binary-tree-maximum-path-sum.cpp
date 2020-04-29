// https://leetcode.com/problems/binary-tree-maximum-path-sum/
// https://www.geeksforgeeks.org/find-maximum-path-sum-in-a-binary-tree/
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
    int maxPathSum(TreeNode *root)
    {
        int res = INT_MIN;
        helper(root, res);
        return res;
    }
    int helper(TreeNode *root, int &res)
    {
        if (root == NULL)
        {
            return 0;
        }

        // l and r store maximum path sum going through left and
        // right child of root respectively
        int l = helper(root->left, res);
        int r = helper(root->right, res);

        // Max path for parent call of root. This path must
        // include at-most one child of root
        // this is the value that will be passed back to the parent node of this root.
        int singleMax = max(max(l, r) + root->val, root->val);

        // Max Top represents the sum when the Node under
        // consideration is the root of the maxsum path and no
        // ancestors of root are there in max sum path
        int maxTop = max(singleMax, l + r + root->val);

        res = max(res, maxTop);

        return singleMax;
    }
};