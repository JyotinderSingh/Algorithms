// https://leetcode.com/problems/two-sum/
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> lookup;
        for (int i = 0; i < nums.size(); ++i)
        {
            int complement = target - nums[i];
            if (lookup.find(complement) != lookup.end())
            {
                return {lookup[complement], i};
            }
            lookup[nums[i]] = i;
        }
        return {-1, -1};
    }
};