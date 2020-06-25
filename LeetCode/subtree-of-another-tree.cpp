// https://leetcode.com/problems/subtree-of-another-tree/

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
    vector<TreeNode *> nodes;

public:
    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        if (!s && !t)
            return true;
        if (!s || !t)
            return false;
        // push all the nodes of s with the same depth as t
        // into the nodes list
        getDepth(s, getDepth(t, -1));

        for (const auto &node : nodes)
        {
            if (isEqual(node, t))
            {
                return true;
            }
        }
        return false;
    }

    int getDepth(TreeNode *root, int target)
    {
        if (!root)
        {
            return 0;
        }

        int depth = max(getDepth(root->left, target), getDepth(root->right, target)) + 1;

        // If depth is equal to target value, add it to the list
        // We send -1 as target depth for t (so that it only returns depth,
        // and doesn't push any nodes)
        if (depth == target)
        {
            nodes.push_back(root);
        }

        return depth;
    }

    bool isEqual(TreeNode *a, TreeNode *b)
    {
        if (!a && !b)
            return true;
        if (!a || !b || a->val != b->val)
            return false;
        return isEqual(a->left, b->left) && isEqual(a->right, b->right);
    }
};

////////////BRUTE FORCE//////////////////////

class Solution
{
public:
    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        if (!s && !t)
            return true;
        if (!s || !t)
            return false;
        return isEqual(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }

    bool isEqual(TreeNode *a, TreeNode *b)
    {
        if (!a && !b)
            return true;
        if (!a || !b)
            return false;
        if (a->val != b->val)
            return false;
        return isEqual(a->left, b->left) && isEqual(a->right, b->right);
    }
};