// https://leetcode.com/problems/power-of-three/
class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        double val = log10(n) / log10(3);
        return floor(val) == ceil(val) && n != 0;
    }
};

///////////////////////////
//// SLOWER //////////////
class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        if (n < 1)
        {
            return false;
        }
        while (n > 1)
        {
            if (n % 3 != 0)
            {
                return false;
            }
            n /= 3;
        }
        return true;
    }
};