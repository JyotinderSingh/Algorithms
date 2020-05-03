// https://leetcode.com/problems/ransom-note/
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int letters[26] = {0};
        for (int i = 0; i < magazine.size(); ++i)
        {
            letters[magazine[i] - 'a']++;
        }
        for (int i = 0; i < ransomNote.size(); ++i)
        {
            if (letters[ransomNote[i] - 'a'] > 0)
            {
                letters[ransomNote[i] - 'a']--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};