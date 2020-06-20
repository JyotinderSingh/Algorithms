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
            return 0;
        }
        queue<TreeNode *> q;
        q.push(root);
        int depth = 0;
        while (!q.empty())
        {
            // count the current levelin depth
            depth++;
            int numberOfNodesAtCurrentLevel = q.size();
            while (numberOfNodesAtCurrentLevel--)
            {
                auto node = q.front();
                q.pop();
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
                // if this is a leaf node, this is the first one we've enccounterd so far,
                // and because we're going in BFS manner, this must be the closest to the root
                if (!node->left && !node->right)
                {
                    return depth;
                }
            }
        }
        return depth;
    }
};