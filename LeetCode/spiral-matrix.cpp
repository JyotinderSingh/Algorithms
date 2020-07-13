// https://leetcode.com/problems/spiral-matrix/
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;

        if (!matrix.size())
            return res;
        int rows = matrix.size(), cols = matrix[0].size();
        int total = rows * cols;
        res.reserve(total);
        int top = 0, down = rows - 1, left = 0, right = cols - 1;

        while (left <= right && top <= down)
        {

            // Traverse right
            for (int i = left; i <= right && res.size() < total; ++i)
            {
                res.push_back(matrix[top][i]);
            }
            top++;
            // Traverse Down
            for (int j = top; j <= down && res.size() < total; ++j)
            {
                res.push_back(matrix[j][right]);
            }
            right--;
            // Traverse left
            for (int i = right; i >= left && res.size() < total; --i)
            {
                res.push_back(matrix[down][i]);
            }
            down--;
            // Traverse up
            for (int j = down; j >= top && res.size() < total; --j)
            {
                res.push_back(matrix[j][left]);
            }
            left++;
        }
        return res;
    }
};

/////////////////////////////////////////
///// SAME BUT DIFFERENT ////////////////
/////////////////////////////////////////

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;

        if (!matrix.size())
            return res;
        int rows = matrix.size(), cols = matrix[0].size();
        int total = rows * cols;
        res.reserve(total);
        int top = 0, down = rows - 1, left = 0, right = cols - 1;

        while (left <= right && top <= down)
        {

            // Traverse right
            for (int i = left; i <= right && res.size() < total; ++i)
            {
                res.push_back(matrix[top][i]);
            }

            // Traverse Down
            for (int j = top + 1; j <= down - 1 && res.size() < total; ++j)
            {
                res.push_back(matrix[j][right]);
            }

            // Traverse left
            for (int i = right; i >= left && res.size() < total; --i)
            {
                res.push_back(matrix[down][i]);
            }

            // Traverse up
            for (int j = down - 1; j >= top + 1 && res.size() < total; --j)
            {
                res.push_back(matrix[j][left]);
            }
            top++, right--, down--, left++;
        }
        return res;
    }
};