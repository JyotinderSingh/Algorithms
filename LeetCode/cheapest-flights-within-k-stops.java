// https://leetcode.com/problems/cheapest-flights-within-k-stops/

class Solution {
  /**
   * Bellman Ford
   */
  public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
    // dp array to keep track of cost to reach each of the n edges.
    int[] cost = new int[n];
    // Initially cost to each edge is inf.
    Arrays.fill(cost, Integer.MAX_VALUE);
    // Cost from src -> src = 0
    cost[src] = 0;

    // We repeat Bellman Ford algo n - 1 times, but we also know
    // k < n and we are allowed at most k stops, so we will just run
    // the algo k + 1 times (because even for 0 stops we run once).
    for (int i = 0; i < k + 1; ++i) {
      // create a temporary copy of the cost array
      // to keep track of new costs from the current iteration.
      // We do not consider the current iteration's changes while
      // calculating the costs. We apply these new costs once the
      // iteration completes.
      int[] temp = Arrays.copyOf(cost, n);
      // Iterate through all the edges
      for (int[] flight : flights) {
        int curr = flight[0], next = flight[1], price = flight[2];

        // Skip the edge if its source vertex has cost of inf.
        if (cost[curr] == Integer.MAX_VALUE) {
          continue;
        }

        // Calculate the cost from the current vertex to the destination
        // on this edge, and update the cost if needed.
        temp[next] = Math.min(temp[next], cost[curr] + price);
      }
      // update the cost array with the new costs.
      cost = temp;
    }
    return cost[dst] == Integer.MAX_VALUE ? -1 : cost[dst];
  }
}

// DFS (TLE)
class Solution {
  int result = Integer.MAX_VALUE;

  public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
    // Each key will represent the from city
    // Each value will be a pair of the destination city and the associated price.
    HashMap<Integer, List<int[]>> graph = new HashMap<>();
    Set<Integer> visited = new HashSet<>();

    for (int[] flight : flights) {
      graph.putIfAbsent(flight[0], new ArrayList<>());
      graph.get(flight[0]).add(new int[] { flight[1], flight[2] });
    }

    dfs(graph, visited, src, dst, k + 1, 0);
    return result == Integer.MAX_VALUE ? -1 : result;
  }

  public void dfs(HashMap<Integer, List<int[]>> graph, Set<Integer> visited, int src, int dst, int k, int cost) {
    // Can't make anymore stops :(
    if (k < 0) {
      return;
    }

    // Base case, we have found a solution.
    if (src == dst) {
      result = cost;
      return;
    }

    // Check if there are any flights originating from this city
    if (!graph.containsKey(src) || visited.contains(src)) {
      return;
    }

    for (int[] flight : graph.get(src)) {
      // prune the path, if when pursuing this path we incur a cost greater
      // than the current result being tracked, there is no need to follow this path.
      if (cost + flight[1] >= result) {
        continue;
      }
      visited.add(src);
      dfs(graph, visited, flight[0], dst, k - 1, cost + flight[1]);
      visited.remove(src);
    }
  }
}