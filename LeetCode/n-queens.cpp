// https://leetcode.com/problems/n-queens/
class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> res;
        vector<int> colPlacements;
        solveNQueens(0, n, colPlacements, res);
        return res;
    }

    void solveNQueens(int row, const int &n, vector<int> &colPlacements, vector<vector<string>> &res)
    {
        if (row == n)
        {
            res.push_back(generateBoardFromPlacements(colPlacements, n));
            return;
        }

        for (int i = 0; i < n; ++i)
        {
            colPlacements.push_back(i);
            if (isValid(colPlacements))
            {
                solveNQueens(row + 1, n, colPlacements, res);
            }
            colPlacements.pop_back();
        }
    }

    bool isValid(const vector<int> &colPlacements)
    {
        int rowBeingChecked = colPlacements.size() - 1;
        for (int prevRow = 0; prevRow < rowBeingChecked; ++prevRow)
        {
            int diff = abs(colPlacements[prevRow] - colPlacements[rowBeingChecked]);
            if (diff == 0 || diff == rowBeingChecked - prevRow)
            {
                return false;
            }
        }
        return true;
    }

    vector<string> generateBoardFromPlacements(const vector<int> &colPlacements, const int &n)
    {
        string filler = "";
        for (int i = 0; i < n; ++i)
        {
            filler += ".";
        }
        vector<string> ans(n, filler);
        for (int i = 0; i < n; ++i)
        {
            ans[i][colPlacements[i]] = 'Q';
        }
        return ans;
    }
};