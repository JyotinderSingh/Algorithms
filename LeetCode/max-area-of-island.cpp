// https://leetcode.com/problems/max-area-of-island/
class Solution
{
    vector<vector<int>> grid;

public:
    int area(int r, int c, vector<vector<bool>> &seen)
    {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || seen[r][c] || grid[r][c] == 0)
        {
            return 0;
        }
        seen[r][c] = true;
        return (1 + area(r + 1, c, seen) + area(r, c + 1, seen) + area(r - 1, c, seen) + area(r, c - 1, seen));
    }

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        this->grid = grid;
        vector<vector<bool>> seen(grid.size(), vector<bool>(grid[0].size(), 0));
        int ans = 0;
        for (int r = 0; r < grid.size(); ++r)
        {
            for (int c = 0; c < grid[0].size(); ++c)
            {
                if (grid[r][c])
                {
                    ans = max(ans, area(r, c, seen));
                }
            }
        }
        return ans;
    }
};

// /////////////////////////////////////////////////////////////////////////
// The below approach is faster, but modifies the input array
// class Solution_fast
// {
//     vector<vector<int>> grid;

// public:
//     int area(int r, int c)
//     {
//         if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0)
//         {
//             return 0;
//         }
//         grid[r][c] = 0;
//         return (1 + area(r + 1, c) + area(r, c + 1) + area(r - 1, c) + area(r, c - 1));
//     }

//     int maxAreaOfIsland(vector<vector<int>> &grid)
//     {
//         this->grid = grid;
//         int ans = 0;
//         for (int r = 0; r < grid.size(); ++r)
//         {
//             for (int c = 0; c < grid[0].size(); ++c)
//             {
//                 if (grid[r][c])
//                 {
//                     ans = max(ans, area(r, c));
//                 }
//             }
//         }
//         return ans;
//     }
// };