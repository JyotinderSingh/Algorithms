// https://leetcode.com/problems/move-zeroes/submissions/
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int write_index = 0, i;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != 0)
            {
                nums[write_index++] = nums[i];
            }
        }
        while (write_index < nums.size())
        {
            nums[write_index++] = 0;
        }
    }
};