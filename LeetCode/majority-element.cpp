// https://leetcode.com/problems/majority-element/
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int maj_index = 0, count = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[maj_index] == nums[i])
            {
                count++;
            }
            else if (count == 0)
            {
                maj_index = i;
                count = 1;
            }
            else
            {
                count--;
            }
        }
        return nums[maj_index];
    }
};