// https://leetcode.com/problems/count-square-submatrices-with-all-ones/submissions/
// Solution explanation: https://www.youtube.com/watch?v=_Lf1looyJMU
#include <bits/stdc++.h>
using namespace std;

int countSquares(vector<vector<int>> &matrix)   
{
    int m = matrix.size(), n = matrix[1].size();
    int count = 0;
    vector<vector<int>> result(m + 1, vector<int>(n + 1, 0)); //initializes the DP matrix with size (m+1, n+1)

    for (int i = 1; i < m + 1; ++i)
    {
        for (int j = 1; j < n + 1; ++j)
        {
            result[i][j] = matrix[i - 1][j - 1] == 0 ? 0
                                                     : min(result[i - 1][j], min(result[i - 1][j - 1], result[i][j - 1])) + 1;
            count += result[i][j];  //addition performed here itself saves time compared to iterating DP matrix in the end
        }
    }

    // output DP matrix
    // for (int i = 0; i < m + 1; ++i)
    // {
    //     for (int j = 0; j < n + 1; ++j)
    //     {
    //         cout << result[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    // Code snippet below only for understanding purpose
    // number of non zero elements in dp matrix is the answer
    // for (int i = 1; i < m + 1; ++i)
    // {
    //     for (int j = 1; j < n + 1; ++j)
    //     {
    //         if (result[i][j] != 0)
    //         {
    //             count += result[i][j];
    //         }
    //     }
    // }

    return count;
}

// tester code
int main()
{
    vector<vector<int>> matrix{{1, 1, 0, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 0, 1, 0, 1}, {0, 0, 1, 0, 1}};
    cout << countSquares(matrix);
}