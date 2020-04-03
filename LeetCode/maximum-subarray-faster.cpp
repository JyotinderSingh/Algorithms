// https://leetcode.com/problems/maximum-subarray/
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        long long int max_ending_here = nums[0];
        long long int max_so_far = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            max_ending_here = nums[i] > (max_ending_here + nums[i]) ? nums[i] : (max_ending_here + nums[i]);
            max_so_far = max_ending_here > max_so_far ? max_ending_here : max_so_far;
        }
        return max_so_far;
    }
};