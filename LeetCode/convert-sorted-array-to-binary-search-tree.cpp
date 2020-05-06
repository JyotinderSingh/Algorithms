// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
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
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if (!nums.size())
        {
            return NULL;
        }
        return helper(nums, 0, nums.size() - 1);
    }

    TreeNode *helper(vector<int> &nums, int left, int right)
    {
        if (left <= right)
        {
            int mid = left + ((right - left) >> 1);
            TreeNode *root = new TreeNode(nums[mid]);
            root->right = helper(nums, mid + 1, right);
            root->left = helper(nums, left, mid - 1);
            return root;
        }
        return NULL;
    }
};