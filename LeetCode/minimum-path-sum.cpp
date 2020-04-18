// https://leetcode.com/problems/minimum-path-sum/submissions/
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        vector<vector<int>> path_sum(grid.size(), vector<int>(grid[0].size(), 0));
        path_sum[0][0] = grid[0][0];
        for (int i = 1; i < grid.size(); ++i)
        {
            path_sum[i][0] = path_sum[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < grid[0].size(); ++j)
        {
            path_sum[0][j] = path_sum[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < grid.size(); ++i)
        {
            for (int j = 1; j < grid[0].size(); ++j)
            {
                path_sum[i][j] = grid[i][j] + min(path_sum[i - 1][j], path_sum[i][j - 1]);
            }
        }
        return path_sum[grid.size() - 1][grid[0].size() - 1];
    }
};