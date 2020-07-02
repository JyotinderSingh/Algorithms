// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

///// PERFORM LEVEL ORDER TRAVERSAL AND REVERSE THE RESULT IN THE END /////
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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> res;
        vector<int> curr;
        if (!root)
        {
            return res;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int numNodes = q.size();
            curr.clear();
            while (numNodes--)
            {
                auto node = q.front();
                q.pop();
                curr.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            res.push_back(curr);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};