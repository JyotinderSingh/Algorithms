// https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3289/
class Solution
{
public:
    int countElements(vector<int> &arr)
    {
        sort(arr.begin(), arr.end(), greater<int>());
        int count = 0;
        vector<int> table(arr.size() + 1, 0);
        for (int i : arr)
        {
            if (i > 0)
            {
                table[i - 1]++;
            }
            if (table[i] > 0)
            {
                count++;
            }
        }
        return count;
    }
};