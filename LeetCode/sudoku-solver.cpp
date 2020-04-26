// https://leetcode.com/problems/sudoku-solver/
class Solution
{
public:
    char EMPTY_ENTRY = '.';
    void solveSudoku(vector<vector<char>> &board)
    {
        canSolveSudokuFromCell(0, 0, board);
    }

    bool canSolveSudokuFromCell(int row, int col, vector<vector<char>> &board)
    {
        // if you overshot your boundary
        if (col == board[row].size())
        {
            // move to the first col of next row
            col = 0, row++;

            if (row == board.size())
            {
                // if you're done scanning the entire board
                return true;
            }
        }

        // skip cells that are already filled out
        if (board[row][col] != EMPTY_ENTRY)
        {
            return canSolveSudokuFromCell(row, col + 1, board);
        }

        for (int value = 1; value <= board.size(); ++value)
        {
            char charToPlace = (char)(value + '0');

            if (canPlaceValue(board, row, col, charToPlace))
            {
                board[row][col] = charToPlace;
                if (canSolveSudokuFromCell(row, col + 1, board))
                {
                    return true;
                }
                board[row][col] = EMPTY_ENTRY;
            }
        }
        return false;
    }

    bool canPlaceValue(vector<vector<char>> &board, int row, int col, char charToPlace)
    {
        // Check column for placement
        for (auto placementRow : board)
        {
            if (charToPlace == placementRow[col])
            {
                return false;
            }
        }

        // Check row for placement
        for (int i = 0; i < board[row].size(); ++i)
        {
            if (charToPlace == board[row][i])
            {
                return false;
            }
        }

        // check region constraints - get size of the sub-box
        int regionSize = (int)sqrt(board.size());

        int verticalBoxIndex = row / regionSize;
        int horizontalBoxIndex = col / regionSize;

        int topLeftOfSubBoxRow = regionSize * verticalBoxIndex;
        int topLeftSubBoxCol = regionSize * horizontalBoxIndex;

        for (int i = 0; i < regionSize; ++i)
        {
            for (int j = 0; j < regionSize; ++j)
            {
                if (charToPlace == board[topLeftOfSubBoxRow + i][topLeftSubBoxCol + j])
                {
                    return false;
                }
            }
        }
        return true;
    }
};
