// https://leetcode.com/problems/symmetric-tree/
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
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }
        if (!root->left && !root->right)
        {
            return true;
        }
        if (!root->left || !root->right)
        {
            return false;
        }

        // Queue for BFS
        queue<TreeNode *> q;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty())
        {
            auto node1 = q.front();
            q.pop();
            auto node2 = q.front();
            q.pop();

            if (node1->val != node2->val)
            {
                return false;
            }

            if (node1->left && node2->right)
            {
                q.push(node1->left);
                q.push(node2->right);
            }
            else if ((!node1->left && node2->right) || (node1->left && !node2->right))
            {
                return false;
            }

            if (node1->right && node2->left)
            {
                q.push(node1->right);
                q.push(node2->left);
            }
            else if ((!node1->right && node2->left) || (node1->right && !node2->left))
            {
                return false;
            }
        }
        return true;
    }
};