// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        int write_index = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] != nums[i - 1])
            {
                nums[write_index] = nums[i];
                write_index++;
            }
        }
        return write_index;
    }
};