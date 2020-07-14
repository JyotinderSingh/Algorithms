// https://leetcode.com/problems/pascals-triangle/

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> pascal_triangle;
        for (int i = 0; i < numRows; ++i)
        {
            vector<int> curr_row;
            for (int j = 0; j <= i; ++j)
            {
                curr_row.push_back((0 < j && j < i) ? pascal_triangle.back()[j - 1] + pascal_triangle.back()[j] : 1);
            }
            pascal_triangle.push_back(curr_row);
        }
        return pascal_triangle;
    }
};

////////////////////////////////////////////////////////////////

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> triangle;

        if (numRows == 0)
        {
            return triangle;
        }

        // first row will always be 1
        triangle.push_back({1});

        for (int i = 1; i < numRows; ++i)
        {
            auto prev_row = triangle.back();

            // current row
            vector<int> curr_row;
            // first element is always 1
            curr_row.push_back(1);

            for (int k = 1; k < i; ++k)
            {
                curr_row.push_back(prev_row[i - k] + prev_row[k]);
            }

            // last element is always 1
            curr_row.push_back(1);

            triangle.push_back(curr_row);
        }
        return triangle;
    }
};