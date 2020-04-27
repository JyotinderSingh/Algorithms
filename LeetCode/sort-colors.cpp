// https://leetcode.com/problems/sort-colors/
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int pivot = 1;
        int smaller = 0, equal = 0, larger = nums.size();

        while (equal < larger)
        {
            if (nums[equal] < pivot)
            {
                swap(nums[smaller], nums[equal]);
                smaller++, equal++;
            }
            else if (nums[equal] == pivot)
            {
                equal++;
            }
            else
            {
                swap(nums[equal], nums[--larger]);
            }
        }
    }
};