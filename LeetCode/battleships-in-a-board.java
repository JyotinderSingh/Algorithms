// https://leetcode.com/problems/battleships-in-a-board/

// Clever approach to avoid dfs.
// Going over all cells, we can count only those that are the "first" cell of 
// the battleship. First cell will be defined as the most top-left cell.
//  We can check for first cells by only counting the 'X' cells that do not have
// an 'X' to the left and do not have an 'X' above them.

class Solution {
  public int countBattleships(char[][] board) {
    int count = 0;
    int rows = board.length, cols = board[0].length;

    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (board[i][j] == '.')
          continue;
        if (i > 0 && board[i - 1][j] == 'X')
          continue;
        if (j > 0 && board[i][j - 1] == 'X')
          continue;
        count++;
      }
    }
    return count;
  }
}

// DFS Approach
class Solution {
  public int countBattleships(char[][] board) {
    int count = 0;
    for (int i = 0; i < board.length; ++i) {
      for (int j = 0; j < board[0].length; ++j) {
        if (board[i][j] == 'X') {
          count++;
          markBattleShip(i, j, board);
        }
      }
    }
    return count;
  }

  void markBattleShip(int i, int j, char[][] board) {
    if (i >= board.length || j >= board[0].length || board[i][j] != 'X')
      return;

    board[i][j] = '*';

    // We can just check both directions since we know that there are no adjacent
    // battleships.
    // In case this is a vertical battleship.
    markBattleShip(i + 1, j, board);
    // In case this is a horizontal battleship.
    markBattleShip(i, j + 1, board);
  }
}