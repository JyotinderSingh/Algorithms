// https://leetcode.com/problems/queue-reconstruction-by-height/
// https://leetcode.com/problems/queue-reconstruction-by-height/discuss/672958/Problem-Explanation-or-Detailed-Steps-Solution-or-Simple-or-Using-Sorting
class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        vector<vector<int>> res;
        sort(people.begin(), people.end(), [&](const auto &a, const auto &b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        for (const auto &p : people)
        {
            res.insert(res.begin() + p[1], p);
        }
        return res;
    }
};