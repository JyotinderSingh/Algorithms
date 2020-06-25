// https://leetcode.com/problems/unique-binary-search-trees-ii/

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
    vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
            return vector<TreeNode *>(0);
        return generateTreesHelper(1, n);
    }

    vector<TreeNode *> generateTreesHelper(int start, int end)
    {
        vector<TreeNode *> res;

        if (start > end)
        {
            res.push_back(nullptr);
        }

        // make node i the root for the current tree
        for (int i = start; i <= end; ++i)
        {

            // generate all possible left subtrees for the current root i
            vector<TreeNode *> leftSubtrees = generateTreesHelper(start, i - 1);

            // generate all possible right subtrees for the current root i
            vector<TreeNode *> rightSubtrees = generateTreesHelper(i + 1, end);

            for (const auto &leftSubtree : leftSubtrees)
            {
                for (const auto &rightSubtree : rightSubtrees)
                {

                    // create the current tree
                    TreeNode *root = new TreeNode(i);
                    root->left = leftSubtree;
                    root->right = rightSubtree;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};