// https://leetcode.com/problems/number-of-1-bits/
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;
        while (n != 0)
        {
            count++;
            n &= (n - 1);
        }
        return count;
    }
};

//////////////////////////////////////

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;
        while (n > 0)
        {
            if (n & 1 == 1)
            {
                count++;
            }
            n >>= 1;
        }
        return count;
    }
};