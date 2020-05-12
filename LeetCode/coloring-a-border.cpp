// https://leetcode.com/problems/coloring-a-border/
class Solution
{
public:
    vector<vector<int>> colorBorder(vector<vector<int>> &grid, int r0, int c0, int color)
    {
        int comp = grid[r0][c0];
        dfs(grid, r0, c0, comp, color);

        // make all negative cells positive we only needed them
        // to be negative for knowing if they'd been visited or not
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] < 0)
                {
                    grid[i][j] *= -1;
                }
            }
        }
        return grid;
    }

    void dfs(vector<vector<int>> &grid, int row, int col, int comp, int newColor)
    {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || abs(grid[row][col]) != comp || grid[row][col] < 0)
        {
            return;
        }
        if ((row - 1 < 0 || (abs(grid[row - 1][col]) != comp && grid[row - 1][col] > 0)) || (row + 1 >= grid.size() || (abs(grid[row + 1][col]) != comp && grid[row + 1][col] > 0)) || (col - 1 < 0 || (abs(grid[row][col - 1]) != comp && grid[row][col - 1] > 0)) || (col + 1 >= grid[0].size() || (abs(grid[row][col + 1]) != comp && grid[row][col + 1] > 0)))
        {
            grid[row][col] = newColor;
        }

        // mark the cell as visited
        grid[row][col] *= -1;

        dfs(grid, row + 1, col, comp, newColor);
        dfs(grid, row - 1, col, comp, newColor);
        dfs(grid, row, col + 1, comp, newColor);
        dfs(grid, row, col - 1, comp, newColor);
    }
};

// CLEANER BUT A LITTLE SLOWER SOLUTION WITH EXTRA SPACE
class Solution
{
public:
    vector<vector<int>> colorBorder(vector<vector<int>> &grid, int r0, int c0, int color)
    {
        int comp = grid[r0][c0];
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        dfs(grid, r0, c0, comp, color, vis);
        return grid;
    }

    void dfs(vector<vector<int>> &grid, int row, int col, int comp, int newColor, vector<vector<int>> &vis)
    {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] != comp || vis[row][col])
        {
            return;
        }
        if (isBorder(grid, vis, row, col, comp))
        {
            grid[row][col] = newColor;
        }

        // mark the cell as visited
        vis[row][col] = 1;

        dfs(grid, row + 1, col, comp, newColor, vis);
        dfs(grid, row - 1, col, comp, newColor, vis);
        dfs(grid, row, col + 1, comp, newColor, vis);
        dfs(grid, row, col - 1, comp, newColor, vis);
    }

    bool isBorder(vector<vector<int>> &grid, vector<vector<int>> vis, int row, int col, int comp)
    {
        if (row - 1 < 0 || col - 1 < 0 || row + 1 >= grid.size() || col + 1 >= grid[0].size())
        {
            return true;
        }
        if (!vis[row - 1][col] && grid[row - 1][col] != comp)
        {
            return true;
        }
        if (!vis[row + 1][col] && grid[row + 1][col] != comp)
        {
            return true;
        }
        if (!vis[row][col - 1] && grid[row][col - 1] != comp)
        {
            return true;
        }
        if (!vis[row][col + 1] && grid[row][col + 1] != comp)
        {
            return true;
        }
        return false;
    }
};
