// https://leetcode.com/problems/excel-sheet-column-number/
class Solution
{
public:
    int titleToNumber(string s)
    {
        long long num = 0;
        int i = 0;
        while (i < s.size())
        {
            num = num * 26 + (s[i] - 'A' + 1);
            i++;
        }
        return num;
    }
};