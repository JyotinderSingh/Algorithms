// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/
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
    unordered_map<int, int> lookup;

public:
    TreeNode *constructFromPrePost(vector<int> &pre, vector<int> &post)
    {
        // create a hashmap for post order array for faster lookup
        for (int i = 0; i < post.size(); ++i)
        {
            lookup[post[i]] = i;
        }
        return helper(0, pre.size() - 1, 0, post.size() - 1, pre, post);
    }

    /*
    * [root][......left......][...right..]  ---pre
    * [......left......][...right..][root]  ---post
    */
    TreeNode *helper(int preStart, int preEnd, int postStart, int postEnd, vector<int> &pre, vector<int> &post)
    {

        TreeNode *root = new TreeNode(pre[preStart]);

        // this node deosn't have any children
        if (preStart == preEnd)
        {
            return root;
        }

        // Index of root of left subtree in preorder
        int RootLeftSubTree = pre[preStart + 1];
        // Index of root of left subtree in postorder
        int RootLeftSubTreePostIdx = lookup[RootLeftSubTree];

        // Number of elements in the left subtree
        int elementsInLeftSubTree = RootLeftSubTreePostIdx - postStart + 1;

        /*
        * For left subtree
        * pre starts from preStart + 1, i.e. the very next element
        * pre ends at preStart + elementsInLeftSubTree - 1
        * post starts at postStart (remains same)
        * post ends at the RootLeftSubTreePostIdx (the rightmost element (the root of left subtree) in the post array)
        */
        root->left = helper(preStart + 1, preStart + elementsInLeftSubTree, postStart, RootLeftSubTreePostIdx, pre, post);

        // if you run out of nodes for right subTree, return the root and
        // let root->right remain NULL
        // Instead of this we can also add a condition in the beginning that checks for
        // postStart > postEnd and returns NULL
        if (RootLeftSubTreePostIdx + 1 == postEnd)
        {
            return root;
        }

        /*
        * For right subtree
        * pre starts at 1 position after the last left subtree element
        * pre ends at preEnd (remains same)
        * post starts at RootLeftSubTreePostIdx + 1
        * post ends at 1 position to the left of postEnd (as postEnd is always current root)
        */
        root->right = helper(preStart + elementsInLeftSubTree + 1, preEnd, RootLeftSubTreePostIdx + 1, postEnd - 1, pre, post);

        return root;
    }
};