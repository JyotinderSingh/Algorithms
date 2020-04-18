// https://leetcode.com/problems/valid-parenthesis-string/
class Solution
{
public:
    bool checkValidString(string s)
    {
        int upper = 0, lower = 0;
        for (char i : s)
        {
            if (i == '(')
            {
                lower++, upper++;
            }
            else if (i == ')')
            {
                lower--, upper--;
            }
            else
            {
                lower--, upper++;
            }
            lower = max(lower, 0);
            if (upper < 0)
            {
                return false;
            }
        }
        return lower == 0;
    }
};
