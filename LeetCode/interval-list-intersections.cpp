// https://leetcode.com/problems/interval-list-intersections/
class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &A, vector<vector<int>> &B)
    {
        vector<vector<int>> res;
        int i = 0, j = 0;

        while (i < A.size() && j < B.size())
        {

            /*
            * Check if A[i] intersects B[j].
            * start - the startpoint of the intersection
            * end - the endpoint of the intersection
            */
            int start = max(A[i][0], B[j][0]);
            int end = min(A[i][1], B[j][1]);
            if (start <= end)
            {
                res.push_back({start, end});
            }

            // remove the interval with the smaller end point
            if (A[i][1] < B[j][1])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        return res;
    }
};