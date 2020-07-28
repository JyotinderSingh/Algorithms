// https://leetcode.com/problems/burst-balloons/

class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        int N = nums.size();

        vector<vector<int>> dp(N, vector<int>(N, 0));

        // Upper-right triangle traversal
        for (int shift = 0; shift < dp.size(); ++shift)
        {
            for (int start = 0; start + shift < dp[0].size(); ++start)
            {
                int end = start + shift;

                // iterate through all possible elements in current window and see which one should be the last one to be popped
                for (int final = start; final <= end; ++final)
                {

                    int left_num = start == 0 ? 1 : nums[start - 1];
                    int right_num = end == N - 1 ? 1 : nums[end + 1];

                    int left_opt = final == start ? 0 : dp[start][final - 1];
                    int right_opt = final == end ? 0 : dp[final + 1][end];

                    int current_value = (left_num * nums[final] * right_num) + left_opt + right_opt;

                    if (dp[start][end] < current_value)
                    {
                        dp[start][end] = current_value;
                    }
                }
            }
        }
        return dp[0][N - 1];
    }
};

//////////////////////////////////////////////////////////////////

class Solution
{
public:
    int maxCoins(vector<int> &balloons)
    {
        int N = balloons.size();
        // First pad the balloons vector with 1's on the left and the right
        balloons.insert(balloons.begin(), 1);
        balloons.insert(balloons.end(), 1);
        // Now our original array is present between indices 1 and N

        vector<vector<int>> dp(balloons.size(), vector<int>(balloons.size(), 0));

        for (int shift = 1; shift <= N; ++shift)
        {
            /*
            * We go on increasing start till start + shift == N + 1, 
            * here, we initialize end = start + shift - 1 => N
            * our main goal is to allow ourselves to access (end + 1) index in balloons
            *
            * We start traversing from [1,1] and go on till [N,N] in the diagonal
            */
            for (int start = 1; start + shift <= N + 1; ++start)
            {
                int end = start + shift - 1;

                int bestValue = 0;
                for (int final = start; final <= end; ++final)
                {

                    // coins from popping the rest of the subranges
                    int coins = dp[start][final - 1] + dp[final + 1][end];

                    // coins from popping the last balloon, at index 'final'
                    coins += balloons[start - 1] * balloons[final] * balloons[end + 1];

                    if (coins > bestValue)
                        bestValue = coins;
                }
                dp[start][end] = bestValue;
            }
        }
        return dp[1][dp[0].size() - 2];
    }
};