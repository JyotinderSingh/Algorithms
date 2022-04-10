// https://leetcode.com/problems/word-search/

class Solution {
  public boolean exist(char[][] board, String word) {
    for (int i = 0; i < board.length; ++i) {
      for (int j = 0; j < board[0].length; ++j) {
        if (dfs(board, word, i, j, 0)) {
          return true;
        }
      }
    }
    return false;
  }

  boolean dfs(char[][] board, String word, int i, int j, int idx) {
    if (i < 0 || i >= board.length || j < 0 || j >= board[0].length || board[i][j] != word.charAt(idx)) {
      return false;
    }

    if (idx == word.length() - 1) {
      return true;
    }

    board[i][j] = '#';

    int[][] moves = new int[][] { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
    for (int[] move : moves) {
      if (dfs(board, word, i + move[0], j + move[1], idx + 1)) {
        return true;
      }
    }

    board[i][j] = word.charAt(idx);
    return false;
  }
}