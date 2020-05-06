// https://leetcode.com/problems/merge-intervals/
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](auto &vec1, auto &vec2) {
            // if the start timings are equal
            if (vec1[0] == vec2[0])
            {
                // place the one with the smaller end time first
                return vec1[1] < vec2[1];
            }
            else
            {
                // place the one with smaller start time first
                return vec1[0] < vec2[0];
            }
        });

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;

        for (int i = 0; i < intervals.size(); ++i)
        {
            // if res != empty and the end time of last added interval is
            // greater than the start time of the current interval
            if (res.size() && res.back()[1] >= intervals[i][0])
            {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
            else
            {
                // if res is empty, simply push the current interval in
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};