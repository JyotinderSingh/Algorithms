// https://leetcode.com/problems/missing-number/
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            res ^= i + 1;
            res ^= nums[i];
        }
        return res;
    }
};