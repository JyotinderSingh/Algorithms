// https://leetcode.com/problems/spiral-matrix-ii/
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> res(n, vector<int>(n));
        int left = 0, top = 0, right = n - 1, down = n - 1;
        int num = 1;
        while (left <= right && top <= down)
        {
            // Traverse right
            for (int j = left; j <= right; ++j)
                res[top][j] = num++;
            top++;

            // Traverse down
            for (int i = top; i <= down; ++i)
                res[i][right] = num++;
            right--;

            // Traverse left
            for (int j = right; j >= left; --j)
                res[down][j] = num++;
            down--;

            // Traverse up
            for (int i = down; i >= top; --i)
                res[i][left] = num++;
            left++;
        }
        return res;
    }
};