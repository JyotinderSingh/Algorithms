// https://leetcode.com/problems/unique-paths/
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        // Build a table of size m x n
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Fill the first row and column with 1's
        // as there's only one way to reach these points
        for (int i = 0; i < m; ++i)
        {
            dp[i][0] = 1;
        }
        for (int i = 0; i < n; ++i)
        {
            dp[0][i] = 1;
        }
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};