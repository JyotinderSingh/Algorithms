// https://leetcode.com/problems/longest-palindromic-subsequence/
class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));

        // Traverse the upper right triangle of dp table, as we scan the string
        // from position i to j (inclusive).
        // dp[i][j] represents length of longest palindromic subsequence
        // between indices i and j (inclusive)
        for (int shift = 0; shift < dp.size(); ++shift)
        {
            for (int i = 0; i + shift < dp[0].size(); ++i)
            {
                int j = i + shift;

                // if the two characters being compared are equal
                if (s[i] == s[j])
                {
                    // 1. if i == j, then simply put 1, as window is 1 char long
                    // 2. in other cases, add 2 to the maxlen for the substring contained
                    // inside s[i] and s[j] (exclusive).
                    dp[i][j] = (i == j) ? 1 : dp[i + 1][j - 1] + 2;
                }
                else
                {
                    // if s[i] != s[j], max length of palindromic subsequence for the current window
                    // will be the same as that for the substring contained inside s[i] and s[j]
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][dp[0].size() - 1];
    }
};