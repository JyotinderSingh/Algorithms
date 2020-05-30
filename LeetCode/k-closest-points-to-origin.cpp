// https://leetcode.com/problems/k-closest-points-to-origin/
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K)
    {
        priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>> pq;
        vector<vector<int>> res;
        for (int i = 0; i < points.size(); ++i)
        {
            pq.push({sqrt(pow(points[i][0], 2) + pow(points[i][1], 2)), points[i]});
            if (pq.size() > K)
            {
                pq.pop();
            }
        }
        while (!pq.empty())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};