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

        // 0 amount using 0 items is true
        dp[0][0] = 1;
        for (int row = 1; row < dp.size(); ++row)
        {
            // can start from j = 1 also, but this is logically more sound
            for (int col = 0; col < dp[0].size(); ++col)
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

/////////////////////////////////////////////////
/////////////////CLEANER CODE////////////////////
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int amount = 0;
        for (const auto &i : nums)
        {
            amount += i;
        }
        if (amount % 2 != 0)
        {
            return false;
        }
        amount /= 2;
        vector<vector<int>> dp(nums.size() + 1, vector<int>(amount + 1, 0));
        // It is possible to get 0 sum, if you choose 0 elements
        dp[0][0] = 1;
        for (int i = 1; i < dp.size(); ++i)
        {
            for (int j = 0; j < dp[0].size(); ++j)
            {
                dp[i][j] = dp[i - 1][j];
                if (nums[i - 1] <= j)
                {
                    dp[i][j] |= dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[dp.size() - 1][dp[0].size() - 1];
    }
};