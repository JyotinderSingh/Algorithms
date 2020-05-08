// https://leetcode.com/problems/check-if-it-is-a-straight-line/submissions/
// http://www.maths.usyd.edu.au/u/MOW/vectors/vectors-11/v-11-7.html
// https://math.stackexchange.com/questions/701862/how-to-find-if-the-points-fall-in-a-straight-line-or-not

class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &coords)
    {
        if (coords.size() < 3)
        {
            return true;
        }

        // If three points lie on the same line then their
        // vector cross product of the lines formed by them must be 0.
        // Vector cross product of 2 lines gives us the area of the
        // parallelogram or triangle (if you divide it by 2) formed by them
        for (int i = 2; i < coords.size(); ++i)
        {
            // we assume lines formed by (Coords[i-2], Coords[i-1]) --> Line 1
            // and (Coords[i-2], Coords[i]) --> Line 2
            int dY1 = coords[i - 1][1] - coords[i - 2][1]; // difference in y coords
            int dX1 = coords[i - 1][0] - coords[i - 2][0]; // difference in x coords

            int dY2 = coords[i][1] - coords[i - 2][1]; // difference in y coords
            int dX2 = coords[i][0] - coords[i - 2][0]; // difference in x coords

            // dX1*dY2 - dX2*dY1 = 0 for 3 points on a straight line
            // as the area of triangle formed by them would be 0
            // This can be written as dX1*dY2 == dX2*dY1
            if (dX1 * dY2 != dX2 * dY1)
            {
                return false;
            }
        }

        return true;
    }
};