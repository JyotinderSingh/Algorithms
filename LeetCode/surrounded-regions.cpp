// https://leetcode.com/problems/surrounded-regions/
class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        /*
        * We will use boundary DFS to solve this problem
        *
        * Let's analyze when an 'O' cannot be flipped,
        * if it has atleast one 'O' in it's adjacent, AND ultimately this chain of adjacent 'O's is connected to some 'O' which lies on boundary of board
        * 
        * consider these two cases for clarity :
        *
        *  O's won't be flipped          O's will be flipped
        * [X O X X X]                   [X X X X X]     
        * [X O O O X]                   [X O O O X]
        * [X O X X X]                   [X O X X X] 
        * [X X X X X]                   [X X X X X]
        *
        * So we can conclude if a chain of adjacent O's is connected some O on boundary then they cannot be flipped
        *
        *
        *  
        * Steps to Solve :
        * 1. Move over the boundary of board, and find O's 
        * 2. Every time we find an O, perform DFS from it's position
        * 3. In DFS convert all 'O' to '#'      (why?? so that we can differentiate which 'O' can be flipped and which cannot be)   
        * 4. After all DFSs have been performed, board contains three elements,#,O and X
        * 5. 'O' are left over elements which are not connected to any boundary O, so flip them to 'X'
        * 6. '#' are elements which cannot be flipped to 'X', so flip them back to 'O'
        */

        if (!board.size())
        {
            return;
        }
        int rows = board.size(), cols = board[0].size();

        for (int i = 0; i < rows; ++i)
        {
            if (board[i][0] == 'O')
            {
                boundaryDFS(board, i, 0);
            }
            if (board[i][cols - 1] == 'O')
            {
                boundaryDFS(board, i, cols - 1);
            }
        }

        for (int j = 0; j < cols; ++j)
        {
            if (board[0][j] == 'O')
            {
                boundaryDFS(board, 0, j);
            }
            if (board[rows - 1][j] == 'O')
            {
                boundaryDFS(board, rows - 1, j);
            }
        }

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (board[i][j] == '#')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }

    void boundaryDFS(vector<vector<char>> &board, const int &i, const int &j)
    {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != 'O')
        {
            return;
        }
        board[i][j] = '#';
        boundaryDFS(board, i + 1, j);
        boundaryDFS(board, i - 1, j);
        boundaryDFS(board, i, j + 1);
        boundaryDFS(board, i, j - 1);
    }
};