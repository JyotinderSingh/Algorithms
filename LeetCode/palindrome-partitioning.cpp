// https://leetcode.com/problems/palindrome-partitioning/
class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        if (s.empty())
        {
            return res;
        }
        vector<string> curr;
        helper(s, 0, res, curr);
        return res;
    }

    void helper(string &s, int pos, vector<vector<string>> &res, vector<string> &cur)
    {
        if (pos == s.size())
        {
            res.push_back(cur);
            return;
        }

        for (int i = pos; i < s.size(); ++i)
        {
            // check if the current slice would be a valid palindrome
            if (isPalindrome(s, pos, i))
            {
                // add the current slice to the current array
                cur.push_back(s.substr(pos, i - pos + 1));
                // go forward from the end of the current slice (i is the right-end index of the slice)
                helper(s, i + 1, res, cur);
                cur.pop_back();
            }
        }
    }

    bool isPalindrome(const string &s, int left, int right)
    {
        while (left <= right)
        {
            if (s[left++] != s[right--])
            {
                return false;
            }
        }
        // cout<<s.substr(left, right - left + 1)<<endl;
        return true;
    }
};