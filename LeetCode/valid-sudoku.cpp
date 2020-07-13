// https://leetcode.com/problems/valid-sudoku/
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (board[i][j] != '.')
                {
                    if (helper(board, i, j))
                    {
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    bool helper(vector<vector<char>> &board, int row, int col)
    {
        // store the value at this position
        char value = board[row][col];

        // temporarily remove it from the board
        board[row][col] = '.';

        // Check the current row
        for (auto ele : board[row])
        {
            if (ele == value)
            {
                board[row][col] = value;
                return false;
            }
        }

        // Check the current column
        for (int i = 0; i < board.size(); ++i)
        {
            if (board[i][col] == value)
            {
                board[row][col] = value;
                return false;
            }
        }

        // Check the subgrid
        int regionSize = (int)sqrt(board.size());

        int verticalBoxIndex = row / regionSize;
        int horizontalBoxIndex = col / regionSize;

        int topLeftOfSubBoxRow = regionSize * verticalBoxIndex;
        int topLeftOfSubBoxCol = regionSize * horizontalBoxIndex;

        for (int i = 0; i < regionSize; ++i)
        {
            for (int j = 0; j < regionSize; ++j)
            {
                if (board[topLeftOfSubBoxRow + i][topLeftOfSubBoxCol + j] == value)
                {
                    board[row][col] = value;
                    return false;
                }
            }
        }

        // Put the value back
        board[row][col] = value;
        return true;
    }
};