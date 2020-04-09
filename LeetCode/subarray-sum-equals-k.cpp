// https://leetcode.com/problems/subarray-sum-equals-k/
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        vector<int> sum(nums.size() + 1, 0);
        int count = 0;
        sum[0] = 0;
        for (int i = 1; i <= nums.size(); ++i)
        {
            sum[i] = sum[i - 1] + nums[i - 1];
        }

        for (int start = 0; start < nums.size(); start++)
        {
            for (int end = start + 1; end <= nums.size(); ++end)
            {
                if (sum[end] - sum[start] == k)
                {
                    count++;
                }
            }
        }
        return count;
    }
};