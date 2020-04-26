// https://leetcode.com/problems/partition-equal-subset-sum/
// https://leetcode.com/problems/partition-equal-subset-sum/discuss/90592/01-knapsack-detailed-explanation
// https://www.youtube.com/watch?v=xCbYmUPvc2Q&t=303s
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int amount = 0;
        for (int num : nums)
        {
            amount += num;
        }
        if (amount % 2 != 0)
        {
            return false;
        }
        amount /= 2;
        vector<vector<int>> dp(nums.size() + 1, vector<int>(amount + 1, 0));
        for (int i = 0; i < dp.size(); ++i)
        {
            dp[i][0] = 1;
        }
        for (int i = 1; i < dp[0].size(); ++i)
        {
            dp[0][i] = 0;
        }
        for (int row = 1; row < dp.size(); ++row)
        {
            for (int col = 1; col < dp[0].size(); ++col)
            {
                dp[row][col] = dp[row - 1][col];
                if (nums[row - 1] <= col)
                {
                    dp[row][col] = dp[row - 1][col] || dp[row - 1][col - nums[row - 1]];
                }
            }
        }
        return dp[nums.size()][amount];
    }
};