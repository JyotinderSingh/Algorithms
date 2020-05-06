// https://leetcode.com/problems/sum-of-two-integers/
class Solution
{
public:
    int getSum(int x, int y)
    {
        while (y)
        {
            int carry = x & y;
            x = x ^ y;
            y = (unsigned int)carry << 1;
        }
        return x;
    }
};