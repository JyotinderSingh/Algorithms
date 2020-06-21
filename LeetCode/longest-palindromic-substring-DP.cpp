// https://leetcode.com/problems/longest-palindromic-substring/
class Solution
{
public:
    string longestPalindrome(string s)
    {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        int longestStart = 0, longestLength = 1;
        for (int shift = 0; shift < dp.size(); ++shift)
        {
            for (int i = 0; i + shift < dp.size(); ++i)
            {
                int j = i + shift;
                if (s[i] == s[j])
                {
                    dp[i][j] = (i + 1 >= j - 1) ? 1 : dp[i + 1][j - 1];
                    if (dp[i][j] && longestLength < (j - i + 1))
                    {
                        longestStart = i;
                        longestLength = j - i + 1;
                    }
                }
            }
        }
        return s.substr(longestStart, longestLength);
    }
};