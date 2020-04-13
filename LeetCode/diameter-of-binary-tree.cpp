// https://leetcode.com/problems/diameter-of-binary-tree/
class Solution
{
public:
    int ans;
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == NULL || (!root->left && !root->right))
        {
            return 0;
        }
        ans = 1;
        depth(root);
        return ans;
    }
    int depth(TreeNode *node)
    {
        if (node == NULL)
            return 0;
        int L = depth(node->left);
        int R = depth(node->right);
        ans = max(ans, L + R);
        return max(L, R) + 1;
    }
};