// https://leetcode.com/problems/search-in-rotated-sorted-array/
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int lo = 0, high = nums.size() - 1;
        int mid = 0;
        // the loop goes on till lo == high
        // i.e. we find the smallest element of the array
        while (lo < high)
        {
            mid = (lo + high) / 2;
            if (nums[mid] > nums[high])
            {
                lo = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        // now mid is the number of elements by which the array
        // has been rotated. We use it to calculate the real mid
        int rot = lo; // lo == high
        lo = 0, high = nums.size() - 1;
        while (lo <= high)
        {
            int mid = (lo + high) / 2;
            int realmid = (mid + rot) % nums.size();
            cout << realmid << endl;
            if (nums[realmid] == target)
            {
                return realmid;
            }
            else if (nums[realmid] < target)
            {
                lo = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return -1;
    }
};