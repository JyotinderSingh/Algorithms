// https://leetcode.com/problems/word-search/
class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {

        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (board[i][j] == word[0])
                {
                    if (dfs(board, word, 0, i, j))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>> &board, string &word, int idx, int row, int col)
    {
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[idx])
        {
            return false;
        }
        if (idx == word.size() - 1)
        {
            return true;
        }

        char curr = board[row][col];
        board[row][col] = '.';

        int moveX[] = {0, 0, 1, -1}, moveY[] = {1, -1, 0, 0};
        for (int i = 0; i < 4; ++i)
        {
            if (dfs(board, word, idx + 1, row + moveY[i], col + moveX[i]))
            {
                return true;
            }
        }

        board[row][col] = curr;
        return false;
    }
};