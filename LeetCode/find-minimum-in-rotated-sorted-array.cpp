// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int idx = -1, n = nums.size();
        int left = 0, right = n - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[n - 1])
            {
                idx = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        int newStart = idx + 1;
        return nums[newStart % n];
    }
};