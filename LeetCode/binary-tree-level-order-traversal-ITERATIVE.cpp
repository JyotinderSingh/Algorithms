// https://leetcode.com/problems/binary-tree-level-order-traversal/
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (!root)
        {
            return res;
        }
        queue<TreeNode *> q;
        q.push(root);
        vector<int> curr_level; //holds the value of the nodes at the current level
        while (!q.empty())
        {
            // keep track of how many nodes are there at the current level before we start adding their children
            int node_count = q.size();
            // clear the nodes from the previous level if any
            curr_level.clear();
            while (node_count--)
            {
                TreeNode *curr = q.front();
                q.pop();

                curr_level.push_back(curr->val);
                if (curr->left)
                {
                    q.push(curr->left);
                }
                if (curr->right)
                {
                    q.push(curr->right);
                }
            }
            // add the nodes at the current level to the result
            res.push_back(curr_level);
        }
        return res;
    }
};