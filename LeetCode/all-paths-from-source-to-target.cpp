// https://leetcode.com/problems/all-paths-from-source-to-target/
// https://leetcode.com/problems/all-paths-from-source-to-target/discuss/118691/C%2B%2BPython-Backtracking

class Solution
{
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<vector<int>> res;
        vector<int> curr;
        helper(graph, res, curr, 0);
        return res;
    }

    void helper(vector<vector<int>> &graph, vector<vector<int>> &res, vector<int> &curr, int src)
    {
        // Add the current node being visited to the path
        curr.push_back(src);

        // If this node is the destination (node 'graph.length - 1') then add the current path to the res
        if (src == graph.size() - 1)
        {
            res.push_back(curr);
        }

        // otherwise continue traversing its neighbours
        else
        {
            for (auto iter : graph[src])
            {
                helper(graph, res, curr, iter);
            }
        }

        // remove the current node from the current path before going back up to the previous recursive call
        curr.pop_back();
    }
};