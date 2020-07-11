// https://leetcode.com/problems/subsets/
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> cur;
        helper(nums, 0, res, cur);
        return res;
    }

    void helper(vector<int> &nums, int i, vector<vector<int>> &res, vector<int> &cur)
    {
        res.push_back(cur);
        // if (i == nums.size())
        //     return;
        for (int j = i; j < nums.size(); ++j)
        {
            cur.push_back(nums[j]);
            helper(nums, j + 1, res, cur);
            cur.pop_back();
        }
    }
};