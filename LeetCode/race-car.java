// https://leetcode.com/problems/race-car/
// https://leetcode.com/problems/race-car/discuss/124326/Summary-of-the-BFS-and-DP-solutions-with-intuitive-explanation

class Solution {
  public int racecar(int target) {
    Deque<int[]> queue = new ArrayDeque<>();
    // Car starts from position 0, with initial speed 1.
    int[] initial = new int[] { 0, 1 };
    queue.offer(initial);

    Set<String> visited = new HashSet<>();
    visited.add(getKey(initial));

    // Start BFS.
    int steps = 0;
    while (!queue.isEmpty()) {
      // Number of positions accessible at the current step count.
      int currLevel = queue.size();
      // Iterate the positions at current level.
      while (currLevel-- > 0) {
        int[] curr = queue.poll();

        // Solution case.
        if (curr[0] == target)
          return steps;

        // Option 1: Accelerate.
        int[] nxt = new int[] { curr[0] + curr[1], curr[1] << 1 };
        String key = getKey(nxt);

        if (!visited.contains(key) && 0 < nxt[0] && nxt[0] < (target << 1)) {
          queue.offer(nxt);
          visited.add(key);
        }

        // Option 2: Reverse.
        nxt = new int[] { curr[0], curr[1] > 0 ? -1 : 1 };
        key = getKey(nxt);

        if (!visited.contains(key) && 0 < nxt[0] && nxt[0] < (target << 1)) {
          queue.offer(nxt);
          visited.add(key);
        }
      }
      steps++;
    }

    return -1;
  }

  String getKey(int[] pos) {
    return pos[0] + " " + pos[1];
  }
}