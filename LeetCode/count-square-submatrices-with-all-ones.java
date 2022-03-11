// https://leetcode.com/problems/count-square-submatrices-with-all-ones/

class Solution {
  public int countSquares(int[][] matrix) {
    int[][] result = new int[matrix.length + 1][matrix[0].length + 1];
    int count = 0;

    for (int i = 1; i < result.length; ++i) {
      for (int j = 1; j < result[0].length; ++j) {
        result[i][j] = matrix[i - 1][j - 1] == 0 ? 0
            : 1 + Math.min(
                Math.min(result[i - 1][j], result[i - 1][j - 1]),
                result[i][j - 1]);
        count += result[i][j];
      }
    }
    return count;
  }
}