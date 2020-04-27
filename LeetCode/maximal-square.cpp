// https://leetcode.com/problems/maximal-square/
class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        if (matrix.empty())
        {
            return 0;
        }
        vector<vector<int>> dp(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        int max_square = 0;
        for (int row = 1; row < dp.size(); row++)
        {
            for (int col = 1; col < dp[0].size(); ++col)
            {
                if (matrix[row - 1][col - 1] == '1')
                {
                    dp[row][col] = min(dp[row - 1][col - 1], min(dp[row - 1][col], dp[row][col - 1])) + 1;
                }
                else
                {
                    dp[row][col] = 0;
                }
                max_square = max(max_square, dp[row][col]);
            }
        }
        return max_square * max_square;
    }
};