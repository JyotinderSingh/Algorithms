// https://leetcode.com/problems/two-city-scheduling/
// https://www.youtube.com/watch?v=vtNoP43hGJA
class Solution
{
public:
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        auto comp = [&](auto &a, auto &b) {
            return a[1] - a[0] > b[1] - b[0];
        };

        sort(costs.begin(), costs.end(), comp);

        int res = 0;

        for (int i = 0; i < costs.size() / 2; ++i)
        {
            res += costs[i][0];
            res += costs[costs.size() - i - 1][1];
        }
        return res;
    }
};