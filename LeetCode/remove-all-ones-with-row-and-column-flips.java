// https://leetcode.com/problems/remove-all-ones-with-row-and-column-flips/

/**
 * You are given an m x n binary matrix grid.
 * 
 * In one operation, you can choose any row or column and flip each value in
 * that row or column (i.e., changing all 0's to 1's, and all 1's to 0's).
 * 
 * Return true if it is possible to remove all 1's from grid using any number of
 * operations or false otherwise.
 * 
 * Example 1:
 * Input: grid = [[0,1,0],[1,0,1],[0,1,0]]
 * Output: true
 * Explanation: One possible way to remove all 1's from grid is to:
 * - Flip the middle row
 * - Flip the middle column
 * 
 * Example 2:
 * Input: grid = [[1,1,0],[0,0,0],[0,0,0]]
 * Output: false
 * Explanation: It is impossible to remove all 1's from grid.
 */

/**
 * Solution Explanation:
 * 
 * Let's say there are some number of 1s in the first row. To get to all 0s
 * matrix it is obvious that we must flip those 1s. If we flip the first row
 * itself then any 0 will turn into 1. So instead we flip all the columns that
 * have 1 in the first row. Now if we think a little deeply, we can realize that
 * we can never flip columns again, because if we do, then 0s in first row will
 * turn to 1s again. So our only option is to flip rows now (starting from
 * second row since first row is already all 0s). Now to get all 0s in the final
 * matrix each row ought to have either only 0s or only 1s. If it has only 0s we
 * don't flip it, if it has only 1s then we flip it. If in any row all the
 * elements are not same, it means it is not possible to get all 0s matrix.
 */

class Solution {
  public boolean removeOnes(int[][] grid) {
    int m = grid.length, n = grid[0].length;

    // Go through the first row and flip all columns that have a 1 in them.
    for (int col = 0; col < n; ++col) {
      if (grid[0][col] == 1) {
        flipColumn(col, grid);
      }
    }

    // Go through the rest of the grid row-wise, starting at (1,1) and check if
    // any of the elements in the row are different from each other.
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; ++j) {
        if (grid[i][j] != grid[i][j - 1])
          return false;
      }
    }
    return true;
  }

  // Helper method to flip a column in the grid.
  public void flipColumn(int col, int[][] grid) {
    for (int row = 0; row < grid.length; ++row) {
      grid[row][col] = 1 - grid[row][col];
    }
  }
}

////////////////////////
/**
 * Explanation:
 * Both rows have to follow the same patterns for us to be able to flip them
 * into all 0s.
 * and by the same patterns, I mean for any two rows, they either have to be
 *  - Exactly the same
 *  - Exactly opposite
 * If there exists a pair of two rows that do not meet the requirements above,
 * we can't flip the table into all 0s.
 * Reason being that we will want to perform column flip if there are two rows
 * that don't meet the requirement above, but when we do col flip, all rows have
 * 1 element flipped as well, so no matter what we do, it won't be doable.
 * 
 * An easy way to check if two rows meet the pattern above is pick a fixed row,
 * comparing the difference between the first element of the two rows, and all
 * the other pairs of elements on these two rows have to have the same
 * difference.
 * 
 * 
 */
class Solution2 {
  public boolean removeOnes(int[][] grid) {
    for (int[] row : grid) {
      for (int j = 0; j < row.length; ++j) {
        if (Math.abs(row[j] - grid[0][j]) != Math.abs(row[0] - grid[0][0]))
          return false;
      }
    }

    return true;
  }
}