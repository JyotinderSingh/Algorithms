// https://leetcode.com/problems/h-index/
class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        for (int i = 0; i < n; ++i)
        {
            if (citations[i] >= n - i)
            {
                return n - i;
            }
        }
        return 0;
    }
};

/////////////////////////////////////////////
///////////////BINARY SEARCH/////////////////
/////////////////////////////////////////////

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        int left = 0, right = n - 1;
        int res = 0;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (citations[mid] >= n - mid)
            {
                res = n - mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return res;
    }
};

//////////////////////