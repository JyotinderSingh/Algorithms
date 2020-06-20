// https://leetcode.com/problems/permutations/
// https://www.youtube.com/watch?v=GCm7m5671Ps&t=1446s
class Solution
{
public:
    void helper(vector<vector<int>> &res, int cur, vector<int> &nums)
    {
        if (cur == nums.size())
        {
            res.push_back(nums);
            return;
        }
        for (int i = cur; i < nums.size(); ++i)
        {
            swap(nums[i], nums[cur]);
            helper(res, cur + 1, nums);
            swap(nums[i], nums[cur]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        int n = nums.size();
        helper(res, 0, nums);
        return res;
    }
};