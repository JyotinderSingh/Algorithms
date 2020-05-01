// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/discuss/85238/Clean-solution-with-detailed-explanation-in-C%2B%2B
// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/discuss/167784/Java-Binary-Search-with-Explanations

// This approach uses BINARY SEARCH
// Note that the index here cannot be used to form the searching space since it's not linear to the numbers in the matrix, 
// whose order lies in two directions unlike the index from 0 to size(size-1).
// Take [[1,4],[3,5]] 2 as an example. If we use the index range as the searching space, l=0, r=3, m=(0+3)/2=1 in the first round 
// and then the numbers smaller than or equal to its number, matrix[m/size][m%size]=matrix[1/2][1%2]=matrix[0][1]=4, are 3 (1, 4 and 3 respectively) 
// and then we will set r=m=1. Just now we have eliminated the potential answer number 3,
// whose index should be 2 matrix[2/2][2%2]=matrix[1][0].
// All of these are because the index sequence is not linear to the matrix numbers whose order lies in two directions.

class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size();
        int lo = matrix[0][0], hi = matrix[n - 1][n - 1];
        while (lo <= hi)
        {
            int mid = lo + ((hi - lo) >> 1);
            if (countNonBigger(mid, matrix) >= k)
            {
                // we need to shrink to seaerch space, as we need a tight bound on
                // the number of elements smaller/equal to mid
                // cuz kth smallest means - k elements smaller than target
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        return lo;
    }

    int countNonBigger(int target, vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        // start searching from top-right
        int i = 0, j = n - 1, count = 0;
        while (i < n && j >= 0)
        {
            if (matrix[i][j] > target)
            {
                // if current element bigger then move one col back
                // as we wanna count number of elements smaller/equal
                j--;
            }
            else
            {
                // j+1 as indices are 0 based
                count += j + 1;
                i++;
            }
        }
        return count;
    }
};