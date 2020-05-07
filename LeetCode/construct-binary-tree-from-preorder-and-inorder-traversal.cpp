// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return helper(0, 0, inorder.size() - 1, preorder, inorder);
    }

    TreeNode *helper(int preStart, int inStart, int inEnd, vector<int> &preorder, vector<int> &inorder)
    {
        /*
        * in case our preStart overshoots the preorder array boundary
        * or inEnd overshoots the inStart index
        * we simply return NULL
        */
        if (preStart >= preorder.size() || inStart > inEnd)
        {
            return NULL;
        }

        // preStart gives the index of the root of the current sub-tree
        TreeNode *root = new TreeNode(preorder[preStart]);

        int inIndex = 0; // the index of the root of this sub-tree in the inorder array
        for (int i = inStart; i <= inEnd; ++i)
        {
            if (inorder[i] == preorder[preStart])
            {
                inIndex = i;
                break;
            }
        }

        /*
        * For the left sub-tree
        * the preStart (index for root of left sub-tree) is simply preStart + 1
        * because the node right after the root node in a preorder traversal is always
        * the root of the left subtree (if it exists).
        * The inStart is still the same, while inEnd becomes inIndex - 1,
        * as the nodes on of the left subtree appear on the left of the root element
        * in the inorder array
        */
        root->left = helper(preStart + 1, inStart, inIndex - 1, preorder, inorder);

        /*
        *   The methodology is pretty much the same for setting inStart and inEnd for the
        * right sub-tree as well. But the main difference occurs in choosing the preStart, 
        * that is the root of the right sub-tree.
        * We do that by skipping all the nodes that belong to the left subtree of the root
        * in the preorder array. We do this by moving ahead (number of elements in left subtree) + 1 steps
        * ahead from the current preStart. Where no. of elements in left subtree = inIndex - inStart
        */
        root->right = helper(preStart + (inIndex - inStart) + 1, inIndex + 1, inEnd, preorder, inorder);

        return root;
    }
};

////////////////////////////////////////////////////
//////// HashMap solution for faster lookup/////////

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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); ++i)
        {
            lookup[inorder[i]] = i;
        }
        return helper(0, 0, inorder.size() - 1, preorder, inorder);
    }

    TreeNode *helper(int preStart, int inStart, int inEnd, vector<int> &preorder, vector<int> &inorder)
    {
        /*
        * in case our preStart overshoots the preorder array boundary
        * or inEnd overshoots the inStart index
        * we simply return NULL
        */
        if (preStart >= preorder.size() || inStart > inEnd)
        {
            return NULL;
        }

        // preStart gives the index of the root of the current sub-tree
        TreeNode *root = new TreeNode(preorder[preStart]);

        int inIndex = lookup[preorder[preStart]]; // the index of the root of this sub-tree in the inorder array

        /*
        * For the left sub-tree
        * the preStart (index for root of left sub-tree) is simply preStart + 1
        * because the node right after the root node in a preorder traversal is always
        * the root of the left subtree (if it exists).
        * The inStart is still the same, while inEnd becomes inIndex - 1,
        * as the nodes on of the left subtree appear on the left of the root element
        * in the inorder array
        */
        root->left = helper(preStart + 1, inStart, inIndex - 1, preorder, inorder);

        /*
        *   The methodology is pretty much the same for setting inStart and inEnd for the
        * right sub-tree as well. But the main difference occurs in choosing the preStart, 
        * that is the root of the right sub-tree.
        * We do that by skipping all the nodes that belong to the left subtree of the root
        * in the preorder array. We do this by moving ahead (number of elements in left subtree) + 1 steps
        * ahead from the current preStart. Where no. of elements in left subtree = inIndex - inStart
        */
        root->right = helper(preStart + (inIndex - inStart) + 1, inIndex + 1, inEnd, preorder, inorder);

        return root;
    }
};