// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
// https://www.youtube.com/watch?v=K0PjrikGKK4

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[right])
            {
                right = mid;
            }
            else if (nums[mid] > nums[right])
            {
                left = mid + 1;
            }
            else
            {
                right--;
            }
        }
        return nums[left];
    }
};

//////////////////////////

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[right])
            {
                right = mid;
            }
            else if (nums[mid] > nums[right])
            {
                left = mid + 1;
            }
            else
            {
                right--;
            }
        }
        return nums[right];
    }
};