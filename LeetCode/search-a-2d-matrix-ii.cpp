// https://leetcode.com/problems/search-a-2d-matrix-ii/

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty())
            return false;
        int col = matrix[0].size() - 1;
        int row = 0;

        while (col >= 0 && row <= matrix.size() - 1)
        {
            /*
        Cases:
          target == item : We found the item. Return true.
          target < item : Target must be to our left...go down in value
          target > item : Target must be to our below...go up in value
      */
            if (target == matrix[row][col])
            {
                return true;
            }
            else if (target < matrix[row][col])
            {
                col--;
            }
            else if (target > matrix[row][col])
            {
                row++;
            }
        }

        return false;
    }
};