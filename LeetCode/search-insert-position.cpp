// https://leetcode.com/problems/search-insert-position/
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        // binary search
        int left = 0, right = nums.size() - 1;
        int idx = -1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target)
            {
                idx = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return idx == -1 ? nums.size() : idx;
    }
};