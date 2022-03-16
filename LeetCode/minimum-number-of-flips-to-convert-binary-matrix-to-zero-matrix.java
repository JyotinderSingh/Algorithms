import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Set;

// https://leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/

class Solution {
  public int minFlips(int[][] mat) {
    // Initiate a config with 0 steps.
    Config init = new Config(mat, 0);

    if (init.isDone())
      return init.step;

    // Configs seen so far.
    Set<String> visited = new HashSet<>();
    visited.add(init.toString());

    // BFS
    Queue<Config> q = new LinkedList<>();
    q.add(init);

    while (!q.isEmpty()) {
      Config c = q.poll();

      // Generate all possible configs from current config
      // by flipping each of the cells (and its neighbours).
      for (Config next : c.getNeighbours()) {
        String nextString = next.toString();
        if (!visited.contains(nextString)) {
          // Check if this is the solution.
          if (next.isDone()) {
            return next.step;
          }
          // Add this config to visited set.
          visited.add(nextString);
          // Add config to queue, to test further by flipping its bits.
          q.add(next);
        }
      }
    }
    return -1;
  }

  // Internal class to represent the matrix config.
  class Config {
    int[][] mat;
    int rows;
    int cols;
    int step; // number of steps taken to generate this config from initial matrix.

    // Constructor.
    Config(int[][] mat, int step) {
      this.mat = mat;
      this.rows = mat.length;
      this.cols = mat[0].length;
      this.step = step;
    }

    // Helper method to check if the current matrix is a zero matrix (solution).
    boolean isDone() {
      for (int i = 0; i < rows; ++i) {
        for (int val : this.mat[i]) {
          if (val != 0) {
            return false;
          }
        }
      }
      return true;
    }

    List<Config> getNeighbours() {
      List<Config> neighbours = new ArrayList<>();

      // Traverse the matrix.
      for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
          neighbours.add(flip(i, j));
        }
      }
      return neighbours;
    }

    private Config flip(int row, int col) {
      int[][] next = new int[rows][cols];
      for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
          // check if this cell is the neighbour of mat[row][col].
          if ((i == row && j == col) || (i == row && j == col + 1) || (i == row && j == col - 1)
              || (i == row + 1 && j == col) || (i == row - 1 && j == col)) {
            // flip the bits.
            next[i][j] = mat[i][j] ^ 1;
          } else {
            next[i][j] = mat[i][j];
          }
        }
      }

      // Increment the step by 1 in resulting matrix, since it was
      // created by flipping the bits.
      return new Config(next, step + 1);
    }

    @Override
    public String toString() {
      return Arrays.deepToString(this.mat);
    }
  }
}