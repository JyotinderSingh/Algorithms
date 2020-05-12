// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (!root)
        {
            return res;
        }
        queue<TreeNode *> q;
        vector<int> currLevel;
        q.push(root);
        int level = -1;
        while (!q.empty())
        {
            level++;
            currLevel.clear();
            int nodeCount = q.size();
            while (nodeCount--)
            {
                auto currNode = q.front();
                q.pop();
                if (currNode->left)
                {
                    q.push(currNode->left);
                }
                if (currNode->right)
                {
                    q.push(currNode->right);
                }
                currLevel.push_back(currNode->val);
            }
            if (level % 2 != 0)
            {
                reverse(currLevel.begin(), currLevel.end());
            }
            res.push_back(currLevel);
        }
        return res;
    }
};