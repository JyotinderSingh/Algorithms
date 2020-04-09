// https://leetcode.com/problems/backspace-string-compare/
class Solution
{
public:
    bool backspaceCompare(string S, string T)
    {
        string res1 = "", res2 = "";
        int ctr = 0;
        for (int i = S.size() - 1; i >= 0; i--)
        {
            if (S[i] == '#')
            {
                ctr++;
            }
            else if (ctr)
            {
                ctr--;
            }
            else
            {
                res1 += S[i];
            }
        }
        ctr = 0;
        for (int i = T.size() - 1; i >= 0; i--)
        {
            if (T[i] == '#')
            {
                ctr++;
            }
            else if (ctr)
            {
                ctr--;
            }
            else
            {
                res2 += T[i];
            }
        }

        return res1 == res2;
    }
};