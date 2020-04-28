// https://leetcode.com/problems/maximum-length-of-repeated-subarray/
class Solution
{
public:
    int findLength(vector<int> &A, vector<int> &B)
    {
        if (!A.size() || !B.size())
        {
            return 0;
        }
        vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));
        int rows = dp.size(), cols = dp[0].size();
        int max_len = 0;
        for (int row = 1; row < rows; ++row)
        {
            for (int col = 1; col < cols; ++col)
            {
                if (A[row - 1] == B[col - 1])
                {
                    dp[row][col] = dp[row - 1][col - 1] + 1;
                }
                max_len = max(max_len, dp[row][col]);
            }
        }
        return max_len;
    }
};