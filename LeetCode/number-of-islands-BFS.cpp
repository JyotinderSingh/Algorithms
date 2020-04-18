// https://leetcode.com/problems/number-of-islands/

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int rows = grid.size(), cols = grid[0].size();
        int count = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (grid[i][j] == '1')
                {
                    count++;

                    // start bfs
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (!q.empty())
                    {
                        pair<int, int> top = q.front();
                        q.pop();

                        int a = top.first, b = top.second;
                        if (a < 0 || b < 0 || a >= rows || b >= cols || grid[a][b] == '0')
                        {
                            continue;
                        }
                        else
                        {
                            grid[a][b] = '0';
                            int moveX[] = {0, 1, -1, 0}, moveY[] = {1, 0, 0, -1};
                            for (int k = 0; k < 4; ++k)
                            {
                                q.push({a + moveX[k], b + moveY[k]});
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};