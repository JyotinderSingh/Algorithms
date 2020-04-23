// https://leetcode.com/problems/first-unique-character-in-a-string/submissions/
class Solution
{
public:
    int firstUniqChar(string s)
    {
        pair<int, int> counts[26];
        for (int i = 0; i < s.size(); ++i)
        {
            counts[s[i] - 'a'].first++;
            counts[s[i] - 'a'].second = i;
        }
        int res = INT_MAX;
        for (auto p : counts)
        {
            if (p.first == 1)
            {
                res = min(res, p.second);
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};