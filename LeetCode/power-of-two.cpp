// https://leetcode.com/problems/power-of-two/
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0)
        {
            return false;
        }
        while (n > 1)
        {
            if (n % 2 != 0)
            {
                return false;
            }
            n /= 2;
        }
        return true;
    }
};

/////////////////////////////////////////////
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n == 0)
        {
            return false;
        }
        return ceil(log2(n)) == floor(log2(n));
    }
};