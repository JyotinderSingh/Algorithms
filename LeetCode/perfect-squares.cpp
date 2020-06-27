// https://leetcode.com/problems/perfect-squares/

// Simple DP - preferred
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i < dp.size(); ++i)
        {
            int j = 1;
            int prod = 1;
            while (prod <= i)
            {
                dp[i] = min(dp[i], dp[i - prod] + 1);
                j++;
                prod = j * j;
            }
        }
        return dp[n];
    }
};

// Bottom Up
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            double sq = sqrt(i);
            // Check if number is perf square
            if ((sq - (int)sq) == 0)
            {
                // if yes then set its dp value as 1
                dp[i] = 1;
                continue;
            }
            else
            {
                for (int j = 1; j < sq; ++j)
                {
                    // look for minimum sum
                    dp[i] = min(dp[i], 1 + dp[i - j * j]);
                }
            }
        }
        return dp[n];
    }
};

// Top Down
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, -1);
        dp[0] = 0, dp[1] = 1;
        return minNums(dp, n);
    }

    int minNums(vector<int> &dp, int n)
    {
        double sq = sqrt(n);
        // The number itself is perf square  hence min nums
        // required to sum upto it are no more than 1 (the num itself)
        if ((sq - (int)sq) == 0)
        {
            return 1;
        }

        if (dp[n] != -1)
        {
            return dp[n];
        }
        int nums = INT_MAX;
        for (int i = 1; i <= sq; ++i)
        {
            nums = min(nums, 1 + minNums(dp, n - i * i));
        }
        dp[n] = nums;
        return dp[n];
    }
};
