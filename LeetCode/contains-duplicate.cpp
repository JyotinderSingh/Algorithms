// https://leetcode.com/problems/contains-duplicate/
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> bag;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (!bag.insert(nums[i]).second)
            {
                return true;
            }
        }
        return false;
    }
};