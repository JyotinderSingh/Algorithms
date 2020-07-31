// https://leetcode.com/problems/maximum-subarray/

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int res = INT_MIN, currSum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            currSum = max(currSum + nums[i], nums[i]);
            res = max(res, currSum);
        }
        return res;
    }
};

/////////////////////////////////////////////////////////

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        vector<long long int> dp(nums.size());
        long long int max_sum = INT_MIN;
        for (int i = 0; i < nums.size(); ++i)
        {
            max_sum = nums[i] > (max_sum + nums[i]) ? nums[i] : (max_sum + nums[i]);
            dp[i] = max_sum;
        }
        return *max_element(dp.begin(), dp.end());
    }
};