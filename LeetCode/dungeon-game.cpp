// https://leetcode.com/problems/dungeon-game/
class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        if (dungeon.size() == 0 || dungeon[0].size() == 0)
            return 1;
        /*
        * This matrix will keep track of the minimum health the knight needs
        * to have when entering a particular dungeon.
        * dp[i][j] = minimum health knight requires, when entering the dungeon[i][j]
        */
        vector<vector<int>> dp(dungeon.size(), vector<int>(dungeon[0].size()));

        int rows = dp.size();
        int cols = dp[0].size();

        // Base case
        dp[rows - 1][cols - 1] = 1 - dungeon[rows - 1][cols - 1];
        dp[rows - 1][cols - 1] = dp[rows - 1][cols - 1] <= 0 ? 1 : dp[rows - 1][cols - 1];

        for (int row = rows - 1; row >= 0; --row)
        {
            for (int col = cols - 1; col >= 0; --col)
            {
                if (row == rows - 1 && col == cols - 1)
                    continue;

                // minimum HP needed to if here, if we are to enter the dungeon to the bottom
                int HP_down = (row == rows - 1) ? INT_MAX : dp[row + 1][col] - dungeon[row][col];

                // minimum HP needed to if here, if we are to enter the dungeon to the right
                int HP_right = (col == cols - 1) ? INT_MAX : dp[row][col + 1] - dungeon[row][col];

                // This will decide which direction we'll end up going
                int HP = min(HP_right, HP_down);
                dp[row][col] = HP <= 0 ? 1 : HP;
            }
        }
        return dp[0][0];
    }
};