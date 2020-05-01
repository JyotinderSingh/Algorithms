// https://leetcode.com/problems/first-bad-version/
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int lo = 0, hi = n;
        while (lo <= hi)
        {
            int mid = lo + ((hi - lo) >> 1);
            if (isBadVersion(mid) == 1)
            {
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        return lo;
    }
};