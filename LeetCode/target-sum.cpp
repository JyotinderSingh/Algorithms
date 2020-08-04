// https://leetcode.com/problems/target-sum/
// https://leetcode.com/problems/target-sum/discuss/97334/Java-(15-ms)-C%2B%2B-(3-ms)-O(ns)-iterative-DP-solution-using-subset-sum-with-explanation

////// DYNAMIC PROGRAMMING - FAST ///////
class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int S)
    {
        int sum = 0;
        for (const auto &ele : nums)
            sum += ele;

        if (sum < S || (S + sum) % 2 != 0)
            return 0;

        return subsetSum(nums, (S + sum) / 2);
    }

    int subsetSum(const vector<int> &nums, int amount)
    {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(amount + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i < dp.size(); ++i)
        {
            for (int j = 0; j < dp[0].size(); ++j)
            {
                dp[i][j] += dp[i - 1][j];
                if (nums[i - 1] <= j)
                {
                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
                }
            }
        }

        return dp[dp.size() - 1][dp[0].size() - 1];
    }
};

//////////////////////////////////////
//////BACKTRACKING + MEMOIZATION//////
//////////////////////////////////////
#define ll long long
class Solution
{
    unordered_map<string, ll> memo;

public:
    int findTargetSumWays(vector<int> &nums, int S)
    {
        return findTargetSumWaysRecur(nums, 0, S);
    }

    int findTargetSumWaysRecur(const vector<int> &nums, int currIndex, ll targetSum)
    {

        auto serial = serialize(currIndex, targetSum);

        if (memo.find(serial) != memo.end())
        {
            return memo[serial];
        }

        if (currIndex == nums.size())
        {
            if (targetSum == 0)
            {
                return 1;
            }
            return 0;
        }

        ll numWaysAdd = findTargetSumWaysRecur(nums, currIndex + 1, targetSum - nums[currIndex]);
        ll numWaysMinus = findTargetSumWaysRecur(nums, currIndex + 1, targetSum + nums[currIndex]);+
        ll totalWays = numWaysAdd + numWaysMinus;

        memo[serial] = totalWays;

        return totalWays;
    }

    string serialize(int currIndex, int targetSum)
    {
        string res = to_string(currIndex) + "," + to_string(targetSum);
        return res;
    }
};