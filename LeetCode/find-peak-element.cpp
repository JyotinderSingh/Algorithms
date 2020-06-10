// https://leetcode.com/problems/find-peak-element/
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        // basic binary search
        // assume the array to be made of small sorted arrays
        // we just need to find one of the local maximas
        int left = 0, right = nums.size() - 1;
        int ans = INT_MIN;
        while (left < right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[mid + 1])
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};