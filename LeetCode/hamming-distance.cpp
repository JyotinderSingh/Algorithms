// https://leetcode.com/problems/hamming-distance/

class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        // all the locations of mismatch become equal to 1
        int z = x ^ y;
        int count = 0;

        // Brian Kernighan’s Algorithm
        while (z)
        {
            z &= (z - 1);
            count++;
        }
        return count;
    }
};