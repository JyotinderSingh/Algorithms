// https://leetcode.com/problems/set-matrix-zeroes/
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        bool isColMarked = false;
        for (int row = 0; row < matrix.size(); ++row)
        {

            // Since first cell for both first row and first column is the same i.e. matrix[0][0]
            // We can use an additional variable for either the first row/column.
            // For this solution we are using an additional variable for the first column
            // and using matrix[0][0] for the first row.
            if (matrix[row][0] == 0)
            {
                isColMarked = true;
            }
            for (int col = 1; col < matrix[0].size(); ++col)
            {
                if (matrix[row][col] == 0)
                {
                    matrix[0][col] = 0;
                    matrix[row][0] = 0;
                }
            }
        }

        // Iterate over the array once again and using the first row and first column, update the elements.
        for (int row = 1; row < matrix.size(); ++row)
        {
            for (int col = 1; col < matrix[0].size(); ++col)
            {
                if (matrix[row][0] == 0 || matrix[0][col] == 0)
                {
                    matrix[row][col] = 0;
                }
            }
        }

        // See if the first row needs to be set to zero as well
        if (!matrix[0][0])
        {
            for (int i = 0; i < matrix[0].size(); ++i)
            {
                matrix[0][i] = 0;
            }
        }

        // See if the first column needs to be set to zero as well
        if (isColMarked)
        {
            for (int i = 0; i < matrix.size(); ++i)
            {
                matrix[i][0] = 0;
            }
        }
    }
};