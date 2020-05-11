// https://leetcode.com/problems/island-perimeter/

class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int sum = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j])
                {
                    sum += (i == 0 || grid[i - 1][j] == 0) + (i == grid.size() - 1 || grid[i + 1][j] == 0) + (j == 0 || grid[i][j - 1] == 0) + (j == grid[0].size() - 1 || grid[i][j + 1] == 0);
                }
            }
        }
        return sum;
    }
};

/////////////////////////////////////////
/////// SLOWER APROACHES ////////////////

/////// TABLE ///////////////////////////
class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        vector<vector<int>> per(grid.size() + 2, vector<int>(grid[0].size() + 2, 0));
        for (int i = 1; i < per.size() - 1; ++i)
        {
            for (int j = 1; j < per[0].size() - 1; ++j)
            {
                per[i][j] = grid[i - 1][j - 1];
            }
        }
        int sum = 0;
        for (int i = 1; i < per.size() - 1; ++i)
        {
            for (int j = 1; j < per[0].size() - 1; ++j)
            {
                if (per[i][j])
                {
                    if (per[i][j + 1] && per[i][j - 1] && per[i - 1][j] && per[i + 1][j])
                    {
                        continue;
                    }
                    sum += (1 - per[i][j + 1]) + (1 - per[i][j - 1]) + (1 - per[i - 1][j]) + (1 - per[i + 1][j]);
                }
            }
        }
        return sum;
    }
};

////// DFS ////////////////////
class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        if (!grid.size())
        {
            return 0;
        }
        pair<int, int> idx = findOne(grid);

        int sum = 0;
        dfs(grid, idx.first, idx.second, sum);
        return sum;
    }

    void dfs(vector<vector<int>> &grid, int i, int j, int &sum)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0 || grid[i][j] == -1)
        {
            return;
        }
        grid[i][j] = -1;
        if (i - 1 >= 0 && grid[i - 1][j] == 0)
        {
            sum++;
        }
        if (i + 1 < grid.size() && grid[i + 1][j] == 0)
        {
            sum++;
        }
        if (j - 1 >= 0 && grid[i][j - 1] == 0)
        {
            sum++;
        }
        if (j + 1 < grid[0].size() && grid[i][j + 1] == 0)
        {
            sum++;
        }
        if (i - 1 < 0)
            sum++;
        if (i + 1 >= grid.size())
            sum++;
        if (j - 1 < 0)
            sum++;
        if (j + 1 >= grid[0].size())
            sum++;
        dfs(grid, i + 1, j, sum);
        dfs(grid, i - 1, j, sum);
        dfs(grid, i, j + 1, sum);
        dfs(grid, i, j - 1, sum);
    }

    pair<int, int> findOne(vector<vector<int>> &grid)
    {
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j])
                {
                    return {i, j};
                }
            }
        }
        return {0, 0};
    }
};