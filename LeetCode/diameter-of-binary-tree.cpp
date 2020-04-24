// https://leetcode.com/problems/diameter-of-binary-tree/
// https://leetcode.com/problems/diameter-of-binary-tree/discuss/574302/cpp-recursive-approach-with-explanation

class Solution
{
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == NULL || (!root->left && !root->right))
        {
            return 0;
        }
        int diameter = 0;
        recursive(root, diameter);
        return diameter;
    }
    int recursive(TreeNode *node, int &diameter)
    {
        if (node == NULL)
            return 0;
        int L = recursive(node->left, diameter);
        int R = recursive(node->right, diameter);
        diameter = max(diameter, L + R);
        return max(L, R) + 1;
    }
};