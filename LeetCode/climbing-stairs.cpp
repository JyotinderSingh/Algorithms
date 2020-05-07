// https://leetcode.com/problems/climbing-stairs/
class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i < dp.size(); ++i)
        {
            for (int j = 1; j <= 2; ++j)
            {
                if (j <= i)
                {
                    dp[i] += dp[i - j];
                }
                // or simply write
                // dp[i] = dp[i - 1] + dp[i - 1]
                // and start outer loop from i = 2
            }
        }
        return dp[n];
    }
};