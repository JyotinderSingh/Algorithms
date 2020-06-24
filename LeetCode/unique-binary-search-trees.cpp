// https://leetcode.com/problems/unique-binary-search-trees/
class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> G(n + 1, 0);
        // 0 nodes - 1 BST rooted at nullptr
        // 1 node - 1 BST with a single node as root
        G[0] = 1, G[1] = 1;

        // Iterating for different values of N, in Bottom Up Approach
        for (int i = 0; i <= n; ++i)
        {

            /*
       * The answer to the ith subproblem will be the summation of F(i, n) for i = 0
       * to i = n (we plant every number we have available at the root)
       * 
       * Remember that we expressed: F(i, n) = G(i - 1) * G(n - i)
       * 
       * The answer to the total unique BST's we can construct with values from 1...n
       * with i representing what is rooted at the root of the tree is F(i, n).
       * 
       * We attain this value by taking the Cartesian Product (fancy word meaning all
       * possible cross products) between all possible unique left BST's and unique
       * right BST's.
       * 
       * All possible unique left BST's count is G[j - 1] if we plant at i.
       * 
       * All possible unique right BST's count is G[i - j] if we plant at i.
       * 
       * Taking a product is the same as taking all pairing between the two sets of
       * possibilites.
       */
            for (int j = 1; j <= i; ++j)
            {
                // Number of total trees possible for current value of i:
                // Possibilities for left subtree  x  Possibilities for right subtree
                G[i] += G[j - 1] + G[i - j];
            }
        }
        return G[n];
    }
};