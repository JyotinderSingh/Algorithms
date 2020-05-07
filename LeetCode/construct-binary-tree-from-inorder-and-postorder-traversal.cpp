// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        return helper(postorder.size() - 1, 0, inorder.size() - 1, inorder, postorder);
    }

    TreeNode *helper(int postStart, int inStart, int inEnd, vector<int> &inorder, vector<int> &postorder)
    {
        /*
        * in case our preStart undershoots the preorder array boundary
        * or inEnd overshoots the inStart index
        * we simply return NULL
        */
        if (postStart < 0 || inStart > inEnd)
        {
            return NULL;
        }

        // preStart gives the index of the root of the current sub-tree
        TreeNode *root = new TreeNode(postorder[postStart]);

        int inIndex = 0; // the index of the root of this sub-tree in the inorder array
        for (int i = inStart; i <= inEnd; ++i)
        {
            if (inorder[i] == postorder[postStart])
            {
                inIndex = i;
                break;
            }
        }

        /*
        * NOTE: First have a look at the root->right assignment and then come back to this
        * The methodology is pretty much the same for setting inStart and inEnd for the
        * right sub-tree as well. But the main difference occurs in choosing the postStart, 
        * that is the root of the left sub-tree.
        * We do that by skipping all the nodes that belong to the left subtree of the root
        * in the preorder array. We do this by moving back (number of elements in right subtree) + 1 steps
        * from the current preStart. Where no. of elements in right subtree = inEnd - inIndex
        */
        root->left = helper(postStart - (inEnd - inIndex) - 1, inStart, inIndex - 1, inorder, postorder);

        /*
        * For the right sub-tree
        * the postStart (index for root of right sub-tree) is simply preStart - 1
        * because the node right before the root node in a postorder traversal is always
        * the root of the right subtree (if it exists).
        * The inEnd is still the same, while inStart becomes inIndex + 1,
        * as the nodes on of the right subtree appear on the right of the root element
        * in the inorder array
        */
        root->right = helper(postStart - 1, inIndex + 1, inEnd, inorder, postorder);

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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        for (int i = 0; i < inorder.size(); ++i)
        {
            lookup[inorder[i]] = i;
        }
        return helper(postorder.size() - 1, 0, inorder.size() - 1, inorder, postorder);
    }

    TreeNode *helper(int postStart, int inStart, int inEnd, vector<int> &inorder, vector<int> &postorder)
    {
        /*
        * in case our preStart undershoots the preorder array boundary
        * or inEnd overshoots the inStart index
        * we simply return NULL
        */
        if (postStart < 0 || inStart > inEnd)
        {
            return NULL;
        }

        // preStart gives the index of the root of the current sub-tree
        TreeNode *root = new TreeNode(postorder[postStart]);

        int inIndex = lookup[postorder[postStart]]; // the index of the root of this sub-tree in the inorder array

        /*
        * NOTE: First have a look at the root->right assignment and then come back to this
        * The methodology is pretty much the same for setting inStart and inEnd for the
        * right sub-tree as well. But the main difference occurs in choosing the postStart, 
        * that is the root of the left sub-tree.
        * We do that by skipping all the nodes that belong to the left subtree of the root
        * in the preorder array. We do this by moving back (number of elements in right subtree) + 1 steps
        * from the current preStart. Where no. of elements in right subtree = inEnd - inIndex
        */
        root->left = helper(postStart - (inEnd - inIndex) - 1, inStart, inIndex - 1, inorder, postorder);

        /*
        * For the right sub-tree
        * the postStart (index for root of right sub-tree) is simply preStart - 1
        * because the node right before the root node in a postorder traversal is always
        * the root of the right subtree (if it exists).
        * The inEnd is still the same, while inStart becomes inIndex + 1,
        * as the nodes on of the right subtree appear on the right of the root element
        * in the inorder array
        */
        root->right = helper(postStart - 1, inIndex + 1, inEnd, inorder, postorder);

        return root;
    }
};