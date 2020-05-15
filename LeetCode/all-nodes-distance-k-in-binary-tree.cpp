// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int K)
    {
        vector<int> res;

        if (!root)
        {
            return res;
        }

        // Keeps track of the parent of each node
        unordered_map<TreeNode *, TreeNode *> parents;
        // Keeps track of which nodes have been visited
        unordered_map<TreeNode *, int> visited;

        // Populate the parents map
        buildMap(root, NULL, parents);

        queue<TreeNode *> q;

        // Start Level Order with the target node
        q.push(target);
        visited[target] = 1;

        int level = 0;

        while (!q.empty())
        {

            if (level == K)
            {
                break;
            }

            int nodeCount = q.size();
            while (nodeCount--)
            {
                auto curr = q.front();
                q.pop();

                if (curr->left && visited[curr->left] != 1)
                {
                    q.push(curr->left);
                    visited[curr->left] = 1;
                }
                if (curr->right && visited[curr->right] != 1)
                {
                    q.push(curr->right);
                    visited[curr->right] = 1;
                }
                if (parents[curr] && visited[parents[curr]] != 1)
                {
                    q.push(parents[curr]);
                    visited[parents[curr]] = 1;
                }
            }
            level++;
        }

        // We broke out of the loop when it contained the nodes for level k
        // (remember that we started at level 0, so AFTER k-1'th iteration you had the required nodes in queue)
        while (!q.empty())
        {
            res.push_back(q.front()->val);
            q.pop();
        }

        return res;
    }

    void buildMap(TreeNode *root, TreeNode *parent, unordered_map<TreeNode *, TreeNode *> &parents)
    {

        parents[root] = parent;

        if (root->left)
        {
            buildMap(root->left, root, parents);
        }

        if (root->right)
        {
            buildMap(root->right, root, parents);
        }
    }
};