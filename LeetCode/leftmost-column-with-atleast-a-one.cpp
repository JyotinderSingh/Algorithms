// https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/530/week-3/3306/
/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution
{
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix)
    {
        int rows = binaryMatrix.dimensions()[0], cols = binaryMatrix.dimensions()[1];
        int ans = cols;
        for (int i = 0; i < rows; ++i)
        {
            int low = 0, high = ans - 1;
            if (ans == 0)
            {
                return ans;
            }
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                if (binaryMatrix.get(i, mid) == 1)
                {
                    ans = min(ans, mid);
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
        }
        return ans == cols ? -1 : ans;
    }
};