// https://leetcode.com/problems/maximum-sum-circular-subarray/
class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &A)
    {

        // Straight forward Kadane's algorithm
        int maxNonCircular = kadane(A);

        /*
        * Now if we wanna find the circular sum, we need to realise
        * that it'll simply be the sum of the entire array, with the 
        * most negatively affecting contiguous chunk of numbers removed
        * That chunk is basically the chunk that adds up to the minimum sum
        * To find that sum, we use the same algorithm, except that now before
        * feeding our array into it, we negate all the elements - this means that
        * the chunk of numbers with the min sum is now the chunk with the max sum
        * And we add this sum to the totalSum of original array to get the result
        */
        int totalSum = 0;
        for (int i = 0; i < A.size(); ++i)
        {
            totalSum += A[i];
            A[i] = -A[i];
        }

        int minSumInverted = kadane(A);
        int maxCircular = totalSum + minSumInverted;

        // if none of the elements was selected in the circular ordering
        if (maxCircular == 0)
        {
            return maxNonCircular;
        }
        return max(maxNonCircular, maxCircular);
    }

    int kadane(vector<int> &A)
    {
        int maxTillHere = -50000;
        int maxSoFar = INT_MIN;
        for (int i = 0; i < A.size(); ++i)
        {
            maxTillHere = max(A[i], maxTillHere + A[i]);
            maxSoFar = max(maxSoFar, maxTillHere);
        }
        return maxSoFar;
    }
};