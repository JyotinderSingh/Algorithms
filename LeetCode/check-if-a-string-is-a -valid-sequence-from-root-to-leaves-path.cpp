// https://leetcode.com/explore/other/card/30-day-leetcoding-challenge/532/week-5/3315/
// Given a binary tree where each path going from the root to any leaf form a valid sequence, check if a given string is a valid sequence in such binary tree.
// We get the given string from the concatenation of an array of integers arr and the concatenation of all values of the nodes along a path results in a sequence in the given binary tree.
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
    bool isValidSequence(TreeNode *root, vector<int> &arr)
    {
        if (!root)
        {
            return false;
        }
        return helper(root, 0, arr);
    }

    bool helper(TreeNode *root, int level, vector<int> &arr)
    {
        if (!root || (level == arr.size()))
        {
            return false;
        }
        if ((level == arr.size() - 1) && (!root->left && !root->right))
        {
            if (arr[level] == root->val)
            {
                return true;
            }
        }
        return root->val == arr[level] && (helper(root->left, level + 1, arr) || helper(root->right, level + 1, arr));
    }
};