// https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/submissions/
class Solution
{
public:
    int numOfSubarrays(vector<int> &arr, int k, int threshold)
    {
        int sum = 0, res = 0, count = 0;
        int start = 0, end = 0;
        while (end < arr.size())
        {
            if (count < k)
            {
                sum += arr[end];
                count++;
                end++;
            }
            else
            {
                sum -= arr[start];
                start++;
                count--;
            }
            if (count == k && sum / k >= threshold)
            {
                res++;
            }
        }
        return res;
    }
};