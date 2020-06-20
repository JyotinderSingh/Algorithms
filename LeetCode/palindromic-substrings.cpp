// https://leetcode.com/problems/palindromic-substrings/
// https://leetcode.com/problems/palindromic-substrings/discuss/258917/Java-Simple-Code%3A-DP-short 
class Solution
{
public:
    int countSubstrings(string s)
    {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        int count = 0;
        for (int shift = 0; shift < dp.size(); ++shift)
        {
            for (int i = 0; i + shift < dp[0].size(); ++i)
            {
                // j defines the column
                int j = i + shift;
                if (s[i] == s[j])
                {
                    dp[i][j] = ((i + 1) >= (j - 1)) ? 1 : dp[i + 1][j - 1];
                    count += dp[i][j];
                }
            }
        }
        return count;
    }
};