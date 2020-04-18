// https://leetcode.com/problems/number-of-islands/
class Solution
{
public:
    // vector<vector<char>> grid;
    void coverArea(vector<vector<char>> &grid, int r, int c)
    {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == '0')
        {
            return;
        }
        grid[r][c] = '0';
        coverArea(grid, r + 1, c);
        coverArea(grid, r, c + 1);
        coverArea(grid, r - 1, c);
        coverArea(grid, r, c - 1);
        return;
    }
    int numIslands(vector<vector<char>> &grid)
    {
        // this->grid = grid;
        int count = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == '1')
                {
                    // cout<<endl<<i<<" "<<j;
                    count++;
                    coverArea(grid, i, j);
                }
            }
        }
        return count;
    }
};