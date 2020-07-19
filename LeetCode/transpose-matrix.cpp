// https://leetcode.com/problems/transpose-matrix/

////////// FASTER APPROACH //////////

class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>> &A)
    {
        vector<vector<int>> res(A[0].size(), vector<int>(A.size()));
        for (int i = 0; i < A.size(); ++i)
        {
            for (int j = 0; j < A[0].size(); ++j)
            {
                res[j][i] = A[i][j];
            }
        }
        return res;
    }
};

////////////////////////////////

class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>> &A)
    {
        vector<vector<int>> res;
        vector<int> temp;
        for (int j = 0; j < A[0].size(); ++j)
        {
            for (int i = 0; i < A.size(); ++i)
            {
                temp.push_back(A[i][j]);
            }
            res.push_back(temp);
            temp.clear();
        }
        return res;
    }
};