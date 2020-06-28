// https://leetcode.com/problems/edit-distance/
// https://www.youtube.com/watch?v=MiqoA-yF-0M
// https://leetcode.com/problems/edit-distance/discuss/25846/C%2B%2B-O(n)-space-DP

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        vector<vector<int>> dp(word2.size() + 1, vector<int>(word1.size() + 1));

        /*
        * Going downwards in the first column (for "" as the first string),
        * we're performing the insert operation
        * And the number of inserts to turn an empty string to a 
        * string with length L is L
        */
        for (int i = 0; i < dp.size(); ++i)
        {
            dp[i][0] = i;
        }

        /*
        * Going towards the right in the first row (for "" as the second string)
        * we're performing the delete operation
        * And the number of deletes to turn a string of length L into an empty
        * string "" is L.
        */
        for (int i = 0; i < dp[0].size(); ++i)
        {
            dp[0][i] = i;
        }

        for (int row = 1; row < dp.size(); ++row)
        {
            for (int col = 1; col < dp[0].size(); ++col)
            {
                if (word1[col - 1] == word2[row - 1])
                {
                    /*
                    * If the characters match, we remove the character from
                    * both the strings, and find the answer to the subproblem
                    * formed by the remaining words (which is located at [row - 1][col - 1])
                    */
                    dp[row][col] = dp[row - 1][col - 1];
                }
                else
                {
                    /*
                    * In case of a mismatch, we see which operation out of
                    * replacement, insertion, and deletion takes the minimum steps
                    * to convert the word1 to word2.
                    */
                    dp[row][col] = min({dp[row - 1][col - 1], dp[row - 1][col], dp[row][col - 1]}) + 1;
                }
            }
        }

        // The last element of the matrix contains the edit distance for the original problem.
        return dp[dp.size() - 1][dp[0].size() - 1];
    }
};