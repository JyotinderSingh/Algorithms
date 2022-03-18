// https://leetcode.com/problems/max-value-of-equation/

/**
 * 
 * Two approaches, PQ and Deque.
 * Start by understanding PQ, then go ahead with Deque
 * 
 * Explanation
 * Because xi < xj,
 * yi + yj + |xi - xj| = (yi - xi) + (yj + xj)
 * 
 * So for each pair of (xj, yj),
 * we have xj + yj, and we only need to find out the maximum yi - xi.
 * To find out the maximum element in a sliding window,
 * we can use priority queue or stack.
 * 
 * Solution 1: Priority Queue
 * Time O(NlogN)
 * Space O(N)
 */

// Priority Queue
// Time O(NlogN), Space O(N).
class Solution {
  public int findMaxValueOfEquation(int[][] points, int k) {
    /**
     * We want to maximise (yi + yj + |xi - xj|). We know
     * xi < xj so eq. simplifies to ((yi - xi) + (yj + xj)).
     * So for each point (say j) we see, we know xj + yj.
     * We just need to maximise (yi - xi).
     * What we do is that we start iterating through the points,
     * keeping track of the max (yi - xi) encountered so far
     * and keep maximising ((yi - xi) + (yj + xj)) for the current
     * point j.
     * Define a priority queue that maximizes (yi - xi)
     * We assume that our xi, yi points come from this PQ.
     * The PQ is sorted based on (yi - xi) in desc order,
     * so the head of the PQ will be the point that maximises
     * (yi - xi). We define secondary sort order based on x value
     * since we also want the condition that |xi - xj| <= k.
     * We also know that xi < xj so eq. becomes xj - xi <= k
     * so we want the inelgible values to also bubble up faster.
     * The condition is likely to not be met if xi is too small.
     * So the second sort order (in case of tie in main order) sorts
     * the elements in ascending order based on xi.
     * So that smaller values (which potentially violate |xi - xj| < k
     * can be eliminated faster in one go from the pq.
     */
    PriorityQueue<Pair<Integer, Integer>> pq = new PriorityQueue<>(
        (a, b) -> a.getKey() == b.getKey() ? a.getValue() - b.getValue() : b.getKey() - a.getKey());
    int res = Integer.MIN_VALUE;

    for (int[] point : points) {
      // Remove all the ineligible points from the PQ.
      // the value of x coordinate will be monotonically increasing
      // as we traverse the list (given condition).
      //
      while (!pq.isEmpty() && point[0] - pq.peek().getValue() > k) {
        pq.poll();
      }
      if (!pq.isEmpty()) {
        // Check if we found a new solution.
        res = Math.max(res, pq.peek().getKey() + (point[0] + point[1]));
      }
      // Add current point to PQ.
      pq.offer(new Pair<>(point[1] - point[0], point[0]));
    }
    return res;
  }
}

// Deque
// Time O(N), Space O(N)
class Solution {
  public int findMaxValueOfEquation(int[][] points, int k) {
    // We want to maintain a monotonically decreasing stack with this
    // Deque where the optimizing condition is (yi - xi).
    Deque<Pair<Integer, Integer>> dq = new ArrayDeque<>();
    int res = Integer.MIN_VALUE;

    for (int[] point : points) {
      // remove all ineligible points.
      while (!dq.isEmpty() && point[0] - dq.peekFirst().getValue() > k) {
        dq.pollFirst();
      }
      // check if result can be updated.
      if (!dq.isEmpty()) {
        res = Math.max(res, (dq.peekFirst().getKey() + point[0] + point[1]));
      }
      // Remove all elements from the back that might result
      // in a smaller value of the optimizing function (yi - xi)
      while (!dq.isEmpty() && dq.peekLast().getKey() < point[1] - point[0]) {
        dq.pollLast();
      }
      // add the current point to the queue.
      dq.offerLast(new Pair<>(point[1] - point[0], point[0]));
    }
    return res;
  }
}