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
                    // i + 1 > j - 1 condition takes care of the conditions when
                    // we are looking at two scenarios:
                    // 1. i == j, that is, the window is 1 char long
                    // 2. when the window is 2 chars long, and there is no
                    // element between them
                    dp[i][j] = ((i + 1) > (j - 1)) ? 1 : dp[i + 1][j - 1];
                    count += dp[i][j];
                }
            }
        }
        return count;
    }
};