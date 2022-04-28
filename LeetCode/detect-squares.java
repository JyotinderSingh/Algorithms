// https://leetcode.com/problems/detect-squares/
// https://leetcode.com/problems/detect-squares/discuss/1471958/C%2B%2BJavaPython-2-approaches-using-HashMap-with-Picture-Clean-and-Concise

import java.util.HashSet;
import java.util.Set;

class DetectSquares {
  int[][] countPoints;
  Set<int[]> points;

  public DetectSquares() {
    this.countPoints = new int[1001][1001];
    this.points = new HashSet<>();
  }

  public void add(int[] point) {
    countPoints[point[0]][point[1]]++;
    points.add(point);
  }

  public int count(int[] point) {
    int x1 = point[0], y1 = point[1];

    int numSquares = 0;

    // From the list of seen points, try to find points that could
    // potentially be at the other end of the diagonal from
    // the query point.
    // If we find a diagonal, finding the other 2 vertices is trivial.
    for (int[] p2 : points) {
      int x2 = p2[0], y2 = p2[1];

      // Skip if this is an empty square or in case this point cannot
      // be a diagonal of the square.
      if (Math.abs(x2 - x1) == 0 || Math.abs(x2 - x1) != Math.abs(y2 - y1)) {
        continue;
      }

      // number of squares = (pairs of vertices we have that could act
      // as the other 2 vertices of the square).
      numSquares += countPoints[x1][y2] * countPoints[x2][y1];
    }

    return numSquares;
  }
}

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares obj = new DetectSquares();
 * obj.add(point);
 * int param_2 = obj.count(point);
 */