// https://leetcode.com/problems/backspace-string-compare/
class Solution
{
public:
    string evaluate(string s)
    {
        string s2;
        for (char ch : s)
        {
            if (ch == '#')
            {
                if (!s2.empty())
                {
                    s2.pop_back();
                }
            }
            else
            {
                s2.push_back(ch);
            }
        }
        return s2;
    }
    bool backspaceCompare(string S, string T)
    {
        return evaluate(S) == evaluate(T);
    }
};