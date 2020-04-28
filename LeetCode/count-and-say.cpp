// https://leetcode.com/problems/count-and-say/
class Solution
{
public:
    string NextNumber(const string &s)
    {
        string res;
        for (int i = 0; i < s.size(); ++i)
        {
            int count = 1;
            while (i + 1 < s.size() && s[i] == s[i + 1])
            {
                count++, i++;
            }
            res += (count + '0');
            res += s[i];
        }
        return res;
    }
    string countAndSay(int n)
    {
        string s = "1";
        for (int i = 1; i < n; ++i)
        {
            s = NextNumber(s);
        }
        return s;
    }
};