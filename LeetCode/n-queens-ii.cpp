// https://leetcode.com/problems/n-queens-ii/
class Solution
{
public:
    int totalNQueens(int n)
    {
        int count = 0;
        vector<int> colPlacements;
        solveNQueens(0, n, colPlacements, count);
        return count;
    }

    void solveNQueens(int row, const int &n, vector<int> &colPlacements, int &count)
    {
        /*
         All n queens have been placed in the n rows. We have
         reached the bottom of our recursion. We can now add
         the colPlacements to the results.
        */
        if (row == n)
        {
            count++;
            return;
        }

        /*
         Try all columns in the current row that we are making
         a choice on.
         The colPlacements list will hold the column we place a
         queen for the i'th row.
         So if I have [ 1, 3, 0, 2 ] that means:
         It is a 4 x 4 board.
         row index 0 has a queen placed in column index 1
         row index 1 has a queen placed in column index 3
         row index 2 has a queen placed in column index 0
         row index 3 has a queen placed in column index 2
        */
        for (int i = 0; i < n; ++i)
        {
            /*
             Record a column placement for this row
            */
            colPlacements.push_back(i);

            /*
             If it is a valid placement we recurse to work on
             the next row (row + 1) in a recursive call
            */
            if (isValid(colPlacements))
            {
                solveNQueens(row + 1, n, colPlacements, count);
            }
            /*
             We are done exploring with that placement and now we
             will remove it from our colPlacements. We will loop
             back around and try more column placements for this
             row (if there are any left)
            */
            colPlacements.pop_back();
        }
        return;
    }

    /*
     Check if a column placement that we just put in the colPlacements
     list is actually valid to recurse on
    */
    bool isValid(const vector<int> &colPlacements)
    {
        /*
         rowWeAreValidatingOn is the row that we just placed a queen on
         and we need to validate the placement
        */
        int rowWeAreValidatingOn = colPlacements.size() - 1;

        /*
         Loop and check our placements in every row previous against
         the placement that we just made
        */
        for (int ithQueenRow = 0; ithQueenRow < rowWeAreValidatingOn; ++ithQueenRow)
        {
            /*
             Get the absolute difference between:
             1.) The column of the already placed queen we are comparing against -> colPlacements.get(ithQueenRow)
             2.) The column of the queen we just placed -> colPlacements.get(rowWeAreValidatingOn)
            */
            int diff = abs(colPlacements[ithQueenRow] - colPlacements[rowWeAreValidatingOn]);

            /*
             1.) absoluteColumnDistance == 0
             If the absolute difference in columns is 0 then we placed in a column being
             attacked by the i'th queen.
             2.) absoluteColumnDistance == rowDistance
             If the absolute difference in columns equals the distance in rows from the
             i'th queen we placed, then the queen we just placed is attacked diagonally.
             For Constraint #2 imagine this:
             [
             ". . Q .",  <--- row 0 (Queen 1)
             "Q . . .",  <--- row 1 (Queen 2)
             ". Q . .",  <--- row 2 (Queen 3)
             ". . . ."
             ]
             1.) 
             Absolute Column Distance Between Queen 2 & 3 == 1.
             Queen 2 is in col 0, Queen 3 is in col 1. 1 - 0 = 1.
             2.)
             Absolute Row Distance Between Queen 2 & 3 == 1
             Queen 2 is in row 1, Queen 3 is in row 2. 2 - 1 = 1.
            */
            int rowDistance = rowWeAreValidatingOn - ithQueenRow;
            if (diff == 0 || diff == rowDistance)
            {
                return false;
            }
        }
        return true;
    }
};