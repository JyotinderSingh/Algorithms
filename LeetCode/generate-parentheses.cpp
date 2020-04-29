// https://leetcode.com/problems/generate-parentheses/
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        helper(res, "", n, 0);
        return res;
    }

    void helper(vector<string> &res, string curr_string, int left_remaining, int right_remaining)
    {
        if (left_remaining == 0 && right_remaining == 0)
        {
            res.push_back(curr_string);
            return;
        }
        if (left_remaining > 0)
        {
            helper(res, curr_string + "(", left_remaining - 1, right_remaining + 1);
        }
        if (right_remaining > 0)
        {
            helper(res, curr_string + ")", left_remaining, right_remaining - 1);
        }
    }
};