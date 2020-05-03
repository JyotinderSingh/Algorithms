// https://leetcode.com/problems/valid-anagram/
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }
        vector<int> countS(26, 0);
        for (int i = 0; i < s.size(); ++i)
        {
            countS[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); ++i)
        {
            if (countS[t[i] - 'a'])
            {
                countS[t[i] - 'a']--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};