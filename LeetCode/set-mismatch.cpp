// https://leetcode.com/problems/set-mismatch/
class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int rep, mis;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[abs(nums[i]) - 1] > 0)
            {
                // make the number's mapping negative as a way of marking its occurence
                nums[abs(nums[i]) - 1] *= -1;
            }
            else
            {
                // if some number's mapping is already negative
                // it means that the same number has appeared before
                rep = abs(nums[i]);
            }
        }
        int missed;
        for (int i = 0; i < nums.size(); ++i)
        {
            // if some number at index i is positive
            // means the number with value i + 1 never appeared
            if (nums[i] > 0)
            {
                mis = i + 1;
                break;
            }
        }
        return {rep, mis};
    }
};