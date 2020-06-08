// https://leetcode.com/problems/search-in-rotated-sorted-array/
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        // idx will contain the index at which the original array would have ended
        int idx = -1;
        int n = nums.size();
        int left = 0, right = n - 1;
        // binary search to find idx
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
        // rotations will be idx + 1
        int rot = idx + 1;
        left = 0, right = n - 1;

        // Apply binary search using this rotation information
        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            // real mid would be the one we use fo comparisons
            int real_mid = (mid + rot) % n;
            if (nums[real_mid] == target)
            {
                return real_mid;
            }
            else if (nums[real_mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return -1;
    }
};