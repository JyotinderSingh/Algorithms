// https://leetcode.com/problems/game-of-life/
/*
* Key:
* -1: The cell is currently alive, but will die in the next state
* 1: The cell is currently live, and will live till the next state as well
* 2: The cell is currently dead, but will become alive in the next state
*/
class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        // Helps us traverse the neighbours of the current cell
        int moves[] = {-1, 0, 1};
        // Keeps track of the number of live neighbours in current state
        int liveNeighbours = 0;

        int rows = board.size();
        int cols = board[0].size();

        for (int row = 0; row < rows; ++row)
        {
            for (int col = 0; col < cols; ++col)
            {

                // Set lilveNeighoburs to 0 initially for every cell
                liveNeighbours = 0;

                // Start scanning neighbours
                for (int i = 0; i < 3; ++i)
                {
                    for (int j = 0; j < 3; ++j)
                    {
                        if (!(moves[i] == 0 && moves[j] == 0))
                        {
                            int r = row + moves[i];
                            int c = col + moves[j];

                            // Check the neighbouring cell and whether
                            // it was a live cell or not
                            if ((r >= 0 && r < rows) && (c >= 0 && c < cols) && abs(board[r][c]) == 1)
                            {
                                liveNeighbours++;
                            }
                        }
                    }
                }

                // Rule 1 or Rule 3
                if (abs(board[row][col]) == 1 && (liveNeighbours < 2 || liveNeighbours > 3))
                {
                    board[row][col] *= -1;
                }

                // Rule 4
                if (board[row][col] == 0 && liveNeighbours == 3)
                {
                    board[row][col] = 2;
                }
            }
        }

        // Update all the values in the matrix
        for (int row = 0; row < rows; ++row)
        {
            for (int col = 0; col < cols; ++col)
            {
                if (board[row][col] > 0)
                {
                    board[row][col] = 1;
                }
                else
                {
                    board[row][col] = 0;
                }
            }
        }
    }
};