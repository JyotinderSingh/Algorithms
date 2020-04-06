// https://leetcode.com/problems/group-anagrams/
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> dict;
        for (string s : strs)
        {
            string temp = s;
            sort(temp.begin(), temp.end());
            dict[temp].push_back(s);
        }
        vector<vector<string>> anagrams;
        for (auto p : dict)
        {
            anagrams.push_back(p.second);
        }
        return anagrams;
    }
};