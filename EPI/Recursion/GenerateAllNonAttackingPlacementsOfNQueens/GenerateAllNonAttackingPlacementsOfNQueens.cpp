#include <bits/stdc++.h>
using namespace std;

void SolveNQueens(int, int, vector<int> *, vector<vector<int>> *);
bool IsValid(const vector<int> &);

vector<vector<int>> NQueens(int n)
{
    vector<vector<int>> result;
    SolveNQueens(n, 0, make_unique<vector<int>>().get(), &result);
    return result;
}
void SolveNQueens(int n, int row, vector<int> *col_placement, vector<vector<int>> *result)
{
    if (row == n)
    {
        result->push_back(*col_placement);
    }
    else
    {
        for (int col = 0; col < n; ++col)
        {
            col_placement->push_back(col);
            if (IsValid(*col_placement))
            {
                SolveNQueens(n, row + 1, col_placement, result);
            }
            col_placement->pop_back();
        }
    }
}

bool IsValid(const vector<int> &col_placement)
{
    int row_id = col_placement.size() - 1;
    for (int i = 0; i < row_id; ++i)
    {
        int diff = abs(col_placement[i] - col_placement[row_id]);
        if (diff == 0 || diff == row_id - i)
        {
            return false;
        }
    }
    return true;
}

// tester code
int main()
{
    int N = 4;
    for (auto v : NQueens(N))
    {
        int idx = 0;
        for (auto i : v)
        {
            cout << "(" << idx << "," << i << ")" << endl;
            idx++;
        }
        cout << endl;
    }
    return 0;
}