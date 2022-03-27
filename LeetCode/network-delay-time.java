// https://leetcode.com/problems/network-delay-time/

// Bellman Ford
class Solution {
  public int networkDelayTime(int[][] times, int n, int k) {
    // Array to keep track of min time to reach a vertex.
    // Size is n + 1 since our indices begin at 1.
    int[] minTime = new int[n + 1];
    // Initial time to each vertex is inf.
    Arrays.fill(minTime, Integer.MAX_VALUE);
    // Time to reach src from src is 0.
    minTime[k] = 0;

    for (int i = 0; i < n - 1; ++i) {
      // clone so as to not contaminate the minTime array before end
      // of current iteration.
      int[] temp = minTime.clone();
      // Go through each edge.
      for (int[] time : times) {
        int src = time[0], dst = time[1], delay = time[2];

        if (minTime[src] == Integer.MAX_VALUE) {
          continue;
        }

        // We take the min time since the shortest time it takes
        // the signal to reach a vertex is counted.
        temp[dst] = Math.min(temp[dst], minTime[src] + delay);
      }
      // replace minTime with results from new iteration.
      minTime = temp;
    }

    int result = 0;
    for (int i = 1; i <= n; ++i) {
      if (minTime[i] == Integer.MAX_VALUE) {
        return -1;
      }
      // The result is the time it took the last vertex to receive the signal.
      result = Math.max(result, minTime[i]);
    }

    return result;
  }
}