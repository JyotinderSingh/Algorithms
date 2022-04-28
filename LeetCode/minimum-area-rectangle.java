// https://leetcode.com/problems/minimum-area-rectangle/

// Optimized approach
// O(n^2) time and O(n) space
//
// This is an optimized approach,
// The cost of comparing two areas is much lower than query operation 
// (in HashMap and HashSet), thus a way to improve this is to first compare 
// areas and then query the points in the set if needed.
// For understanding purpose, second solution is more intuitive.
class Solution {
  public int minAreaRect(int[][] points) {
    Map<Integer, Set<Integer>> pSet = new HashMap<>();
    // Copy all the elements into the hashSet.
    for (int[] point : points) {
      if (!pSet.containsKey(point[0])) {
        pSet.put(point[0], new HashSet<>());
      }
      pSet.get(point[0]).add(point[1]);
    }

    int minArea = Integer.MAX_VALUE;

    // Try to find points that could be diagonal of each other.
    // Then predict the position of the other two vertices
    // and check if they actually exist in this set.
    for (int[] p1 : points) {
      for (int[] p2 : points) {

        // Two points can't be at a diagonal of a rectangle
        // if their x or y coord are same.
        if (p1[0] == p2[0] || p1[1] == p2[1]) {
          continue;
        }

        // Calculate Area
        int currArea = Math.abs(p1[0] - p2[0]) * Math.abs(p1[1] - p2[1]);

        // Check if the other two potential vertices of the rectangle actually exist.
        if (currArea < minArea && pSet.get(p1[0]).contains(p2[1]) && pSet.get(p2[0]).contains(p1[1])) {
          minArea = currArea;
        }
      }
    }

    return minArea == Integer.MAX_VALUE ? 0 : minArea;
  }
}

/// Same approach, more intuitive but little less performant.

class Solution {
  public int minAreaRect(int[][] points) {
    Map<Integer, Set<Integer>> pSet = new HashMap<>();
    // Copy all the elements into the hashSet.
    for (int[] point : points) {
      if (!pSet.containsKey(point[0])) {
        pSet.put(point[0], new HashSet<>());
      }
      pSet.get(point[0]).add(point[1]);
    }

    int minArea = Integer.MAX_VALUE;

    // Try to find points that could be diagonal of each other.
    // Then predict the position of the other two vertices
    // and check if they actually exist in this set.
    for (int[] p1 : points) {
      for (int[] p2 : points) {

        // Two points can't be at a diagonal of a rectangle
        // if their x or y coord are same.
        if (p1[0] == p2[0] || p1[1] == p2[1]) {
          continue;
        }

        // Check if the other two potential vertices of the rectangle actually exist.
        if (pSet.get(p1[0]).contains(p2[1]) && pSet.get(p2[0]).contains(p1[1])) {
          // Calculate Area and upadte minArea if needed.
          minArea = Math.min(minArea, Math.abs(p1[0] - p2[0]) * Math.abs(p1[1] - p2[1]));
        }
      }
    }

    return minArea == Integer.MAX_VALUE ? 0 : minArea;
  }
}