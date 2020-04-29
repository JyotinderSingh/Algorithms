// https://leetcode.com/problems/bitwise-and-of-numbers-range/
class Solution
{
public:
    int rangeBitwiseAnd(int m, int n)
    {
        // all we need to do is find the common prefix for the
        // two numbers making the boundaries of the interval
        // and that prefix followed by all zeroes will be the answer.
        // because all the positions before that would have had a 0
        // at one point or the other - making the final AND result for
        // those positions 0.
        int answer = 0;
        for (int bit = 30; bit >= 0; bit--)
        {
            if ((m & (1 << bit)) != (n & (1 << bit)))
            {
                break;
            }
            else
            {
                answer |= (m & (1 << bit));
            }
        }
        return answer;
    }
};