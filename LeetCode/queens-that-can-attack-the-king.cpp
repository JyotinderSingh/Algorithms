// https://leetcode.com/problems/queens-that-can-attack-the-king/

class Solution
{
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>> &queens, vector<int> &king)
    {
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        vector<vector<int>> res;
        unordered_set<int> qs;
        for (int i = 0; i < queens.size(); i++)
            qs.insert(queens[i][0] * 8 + queens[i][1]);
        for (int i = 0; i < 8; i++)
        {
            int x = king[0], y = king[1];
            while (x >= 0 && x < 8 && y >= 0 && y < 8)
            {
                if (qs.find(x * 8 + y) != qs.end())
                {
                    res.push_back({x, y});
                    break;
                }
                x += dir[i][0], y += dir[i][1];
            }
        }

        return res;
    }
};