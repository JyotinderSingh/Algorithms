// https : //leetcode.com/problems/longest-increasing-subsequence/
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        if (!nums.size())
        {
            return 0;
        }
        vector<int> dp(nums.size(), 1);
        int LIS = 1;
        for (int j = 0; j < nums.size(); ++j)
        {
            for (int i = 0; i < j; ++i)
            {
                if (nums[j] > nums[i])
                {
                    dp[j] = dp[j] > dp[i] + 1 ? dp[j] : dp[i] + 1;
                }
            }
            LIS = dp[j] > LIS ? dp[j] : LIS;
        }
        return LIS;
    }
};