// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> letters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        if (digits.empty())
            return res;
        string curr;
        generate(res, curr, letters, digits, 0);
        return res;
    }

    void generate(vector<string> &res, string curr, const vector<string> &letters, const string &digits, int idx)
    {
        if (idx == digits.size())
        {
            res.push_back(curr);
            return;
        }

        for (int i = 0; i < letters[digits[idx] - '0'].size(); ++i)
        {
            curr += letters[digits[idx] - '0'][i];
            generate(res, curr, letters, digits, idx + 1);
            curr.pop_back();
        }
    }
};