// https://leetcode.com/problems/house-robber/
// https://leetcode.com/problems/house-robber/discuss/156523/From-good-to-great.-How-to-approach-most-of-DP-problems.

/////////////////////////////////
////// BOTTOM UP ITERATIVE //////
////// O(1) SPACE O(N) TIME /////
/////////////////////////////////

class Solution
{
public:
    int rob(vector<int> &nums)
    {

        if (nums.empty())
            return 0;

        int prev = 0, one_before_prev = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            int temp = prev;
            prev = max(one_before_prev + nums[i], prev);
            one_before_prev = temp;
        }
        return prev;
    }
};

/////////////////////////////////
////// BOTTOM UP ITERATIVE //////
////// O(N) SPACE O(N) TIME /////
/////////////////////////////////

class Solution
{
public:
    int rob(vector<int> &nums)
    {

        if (nums.empty())
            return 0;

        vector<int> dp(nums.size(), -1);

        for (int i = 0; i < dp.size(); ++i)
        {
            dp[i] = max((i - 2 >= 0 ? dp[i - 2] : 0) + nums[i], (i > 0 ? dp[i - 1] : 0));
        }
        return dp.back();
    }
};

//////////////////////////////////
///// TOP DOWN MEMO RECURSIVE ////
//////////////////////////////////

class Solution
{
    vector<int> memo;

public:
    int rob(vector<int> &nums)
    {
        memo = vector<int>(nums.size(), -1);
        return rob(nums, nums.size() - 1);
    }
    int rob(vector<int> &nums, int idx)
    {
        if (idx < 0)
            return 0;
        if (memo[idx] >= 0)
            return memo[idx];
        memo[idx] = max(rob(nums, idx - 2) + nums[idx], rob(nums, idx - 1));
        return memo[idx];
    }
};