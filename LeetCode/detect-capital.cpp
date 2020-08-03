// https://leetcode.com/problems/detect-capital/
class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        int capitals = 0, idx = -1;
        for (int i = 0; i < word.size(); ++i)
        {
            if (word[i] >= 65 && word[i] <= 90)
                capitals++, idx = i;
        }
        if (capitals == word.size())
            return true;
        if (capitals != word.size() && idx == 0)
            return true;
        if (capitals == 0)
            return true;
        return false;
    }
};