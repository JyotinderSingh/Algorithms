// https://www.leetcode.com/problems/valid-sudoku/
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        const int n = board.size();
        int sqrt_n = (int)sqrt(board.size());
        /*
        * The 3 matrices keep track if the current element has already occured
        * before in that row/col/subgrid before.
        * checkRow[i][num] ---> tracks if num has appeared in i'th row
        * checkCol[j][num] ---> tracks if num has appeared in j'th column
        * checkSubGrid[k][num] ---> tracks if num has appeared in k'th sub grid
        *
        *   k takes following values for each subgrid:
        *   0   1   2
        *   3   4   5
        *   6   7   8
        */
        int checkRow[9][9] = {0}, checkCol[9][9] = {0}, checkSubGrid[9][9] = {0};

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (board[i][j] != '.')
                {

                    // we decrease the value by one to fit all values in
                    // our three 9x9 tracking matrices
                    int value = board[i][j] - '0' - 1;

                    // calculate the subgrid number
                    int k = ((i / sqrt_n) * sqrt_n) + (j / sqrt_n);

                    // check if the value has appeared in an illegal position before
                    if (checkRow[i][value] || checkCol[j][value] || checkSubGrid[k][value])
                    {
                        return false;
                    }
                    checkRow[i][value] = checkCol[j][value] = checkSubGrid[k][value] = 1;
                }
            }
        }
        return true;
    }
};