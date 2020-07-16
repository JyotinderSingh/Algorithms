// https://leetcode.com/problems/maximum-width-of-binary-tree/
// https://leetcode.com/problems/maximum-width-of-binary-tree/discuss/106645/C%2B%2BJava-*-BFSDFS3liner-Clean-Code-With-Explanation
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
#define ull unsigned long long int

class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        vector<ull> lefts;
        return getWidth(root, 1, 0, lefts);
    }

    ull getWidth(TreeNode *root, ull id, int depth, vector<ull> &lefts)
    {
        if (!root)
            return 0;

        // if you're visiting this level for the first time
        // it means you're at the leftmost node (we are doing inorder traversal)
        if (depth >= lefts.size())
            lefts.push_back(id);

        // return the max of all possible widths
        return max({id - lefts[depth] + 1, getWidth(root->left, id * 2, depth + 1, lefts), getWidth(root->right, id * 2 + 1, depth + 1, lefts)});
    }
};