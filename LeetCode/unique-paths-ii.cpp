// https://leetcode.com/problems/unique-paths-ii/

////////// WITHOUT EXTRA SPACE ///////////
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        if (obstacleGrid[0][0] == 1)
            return 0;

        obstacleGrid[0][0] = 1;

        for (int i = 0; i < obstacleGrid.size(); ++i)
        {
            for (int j = 0; j < obstacleGrid[0].size(); ++j)
            {
                if (i == 0 && j == 0)
                    continue;

                if (obstacleGrid[i][j] == 1)
                {
                    obstacleGrid[i][j] = 0;
                }
                else
                {
                    obstacleGrid[i][j] += i > 0 ? obstacleGrid[i - 1][j] : 0;
                    obstacleGrid[i][j] += j > 0 ? obstacleGrid[i][j - 1] : 0;
                }
            }
        }
        return obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
    }
};

/////////////////////////////////////////
/////////// WITH EXTRA SPACE ////////////
/////////////////////////////////////////

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &grid)
    {
        // add an extra row and column in DP table in addition to the grid dimensions
        // (helps with cases where you have obstacles in first row or column)
        vector<vector<int>> dp(grid.size() + 1, vector<int>(grid[0].size() + 1, 0));

        // Check if it is possible to start
        dp[1][1] = grid[0][0] ? 0 : 1;

        // traverse the grid
        for (int i = 1; i < dp.size(); ++i)
        {
            for (int j = 1; j < dp[0].size(); ++j)
            {
                // skip checking the first index (we already set it)
                if (i == 1 && j == 1)
                    continue;

                // add the number of possible paths to the previous cells
                dp[i][j] = grid[i - 1][j - 1] ? 0 : dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[dp.size() - 1][dp[0].size() - 1];
    }
};