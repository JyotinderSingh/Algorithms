// https://leetcode.com/problems/coin-change-2/
class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1));
        // filling 0th column with all 1's
        // as there is 1 way to make 0 amount using whatever coins
        // i.e. picking up none
        int rows = dp.size(), cols = dp[0].size();
        for (int i = 0; i < rows; ++i)
        {
            dp[i][0] = 1;
        }
        // filling 0th row from 1st col onwards
        // with 0's as there is no way to make
        // amount > 0 using no coins
        for (int j = 1; j < cols; ++j)
        {
            dp[0][j] = 0;
        }

        // dp[row][col] = dp[row-1][col] + dp[row][col - coins[row - 1]]
        for (int row = 1; row < rows; ++row)
        {
            for (int col = 1; col < cols; ++col)
            {
                if (coins[row - 1] <= col)
                {
                    dp[row][col] = dp[row - 1][col] + dp[row][col - coins[row - 1]];
                }
                else
                {
                    dp[row][col] = dp[row - 1][col];
                }
            }
        }
        return dp[rows - 1][cols - 1];
    }
};

//optimized approach below
// class Solution
// {
// public:
//     int change(int amount, vector<int> &coins)
//     {
//         vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));
//         int rows = dp.size(), cols = dp[0].size();
//         dp[0][0] = 1;
//         for (int row = 1; row < rows; ++row)
//         {
//             dp[row][0] = 1;
//             for (int col = 1; col < cols; ++col)
//             {
//                 int currentCoinValue = coins[row - 1];
//                 int withoutThisCoin = dp[row - 1][col];
//                 int withThisCoin = currentCoinValue <= col ? dp[row][col - currentCoinValue] : 0;
//                 dp[row][col] = withThisCoin + withoutThisCoin;
//             }
//         }
//         return dp[rows - 1][cols - 1];
//     }
// };