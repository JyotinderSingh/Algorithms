// https://leetcode.com/problems/cheapest-flights-within-k-stops/
// https://leetcode.com/problems/cheapest-flights-within-k-stops/discuss/662812/C%2B%2B-BFS-or-Bellman-Ford-Algo-or-Dijkstra-Algo
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K)
    {
        // Bellman Ford Algorithm
        // Time complexity of Bellman-Ford is O(VE)
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // We only want to have at most K stops, so we only run the loop K + 1 times.
        for (int i = 0; i < K + 1; ++i)
        {
            /*
            * we create this temporary array, so that we don't simultaneously keep updating the values for the distances,
            * the way we do in usual bellman ford algo - because that would mean that we are introducing new paths with the
            * help of other nodes, which in essence would mean that we are introducing a new stop. 
            * This messes up the calculation, so we postpone all distance updates till the end of the current loop.
            */
            vector<int> temp(dist);
            for (const auto &flight : flights)
            {
                if (dist[flight[0]] != INT_MAX)
                {
                    temp[flight[1]] = min(temp[flight[1]], dist[flight[0]] + flight[2]);
                }
            }
            dist = temp;
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};



////////////////////////////////////////////////////
/////////////// DIJKSTRA ///////////////////////////
////////////////////////////////////////////////////
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K)
    {
        // Dijkstra's Algorithm

        // Create a graph
        unordered_map<int, vector<pair<int, int>>> adjList;
        for (const auto &iter : flights)
        {
            adjList[iter[0]].push_back({iter[1], iter[2]});
        }

        // create a minHeap (comparator uses first element of array to compare by defualt)
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, K + 1});
        while (!pq.empty())
        {
            // get element with minimum cost
            auto temp = pq.top();
            pq.pop();
            int cost = temp[0];
            int cur = temp[1];
            int stop = temp[2];

            // is the popped element is the destination, then finish
            if (cur == dst)
            {
                return cost;
            }

            // if you still have stops left
            if (stop > 0)
            {
                // add all the neighbouring nodes of the current node to the minHeap
                for (const auto &next : adjList[cur])
                {
                    // cost will be cost till the current node + edge weight
                    // decrease the stop number as you go further because you added a stop
                    pq.push({cost + next.second, next.first, stop - 1});
                }
            }
        }
        return -1;
    }
};