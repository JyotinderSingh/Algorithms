// https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3289/
// Given an integer array arr, count element x such that x + 1 is also in arr.

// If there're duplicates in arr, count them seperately.
class Solution
{
public:
    int countElements(vector<int> &arr)
    {
        unordered_map<int, int> dict;
        int count = 0;
        for (int i : arr)
        {
            dict[i] = 1;
        }
        for (int i : arr)
        {
            if (dict.find(i + 1) != dict.end())
            {
                count++;
            }
        }
        return count;
    }
};