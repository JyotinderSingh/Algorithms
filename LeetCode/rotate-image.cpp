// https://leetcode.com/problems/rotate-image/
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = i; j < matrix.size(); ++j)
            {
                swap(matrix[j][i], matrix[i][j]);
            }
        }

        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[i].size() / 2; ++j)
            {
                swap(matrix[i][j], matrix[i][matrix[i].size() - 1 - j]);
            }
        }
    }
};