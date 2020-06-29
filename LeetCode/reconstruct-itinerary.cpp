// https://leetcode.com/problems/reconstruct-itinerary/
// https://leetcode.com/problems/reconstruct-itinerary/discuss/78835/28ms-C%2B%2B-beats-100-Short-and-Elegant.
class Solution
{
public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
        // Add all the nodes to a graph
        for (const auto &ticket : tickets)
        {
            graph[ticket[0]].push(ticket[1]);
        }
        vector<string> res;
        // start from JFK (acc. to question)
        dfs(graph, res, "JFK");

        // the destinations get added in reverse order in our dfs implementation
        reverse(res.begin(), res.end());
        return res;
    }

    void dfs(unordered_map<string, priority_queue<string, vector<string>, greater<string>>> &graph, vector<string> &res, string src)
    {
        /*
        * first iterate over all the neighbours until you find a valid path
        * adding the destination to the res after the while loop takes care of the order:
        * The possible cases are:
        * 1. In case a path is not valid, the src node has no neighbours - so it directly gets 
        *   added to the end of the result (res is being build in reverse order)
        * 2. In case a path is valid, we explore its neighbours first, as they will be visited after it,
        *   and they need to occur first in the res array (cuz we are building it in reverse order)
        */
        while (!graph[src].empty())
        {
            const auto dst = graph[src].top();
            graph[src].pop();
            dfs(graph, res, dst);
        }
        res.push_back(src);
    }
};