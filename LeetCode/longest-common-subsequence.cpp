// https://leetcode.com/problems/longest-common-subsequence/
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        if (!text1.size() || !text2.size())
        {
            return 0;
        }
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        for (int i = 1; i < dp.size(); ++i)
        {
            for (int j = 1; j < dp[0].size(); ++j)
            {

                if (text1[i - 1] == text2[j - 1])
                {
                    // characters match, so remove it from both the strings
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    // removing a character from one of the strings and seeing
                    // which removal gives a better result
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp[dp.size() - 1][dp[0].size() - 1];
    }
};