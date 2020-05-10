// https://leetcode.com/problems/powx-n/submissions/
class Solution
{
public:
    double myPow(double x, int n)
    {
        if (x == 0)
        {
            return 1;
        }
        if (x == 1)
        {
            return x;
        }
        return getPow(x, n);
    }
    double getPow(double x, int pow)
    {
        if (pow == 0)
        {
            return 1;
        }

        double temp = getPow(x, pow / 2);
        if (pow % 2 == 0)
        {
            return temp * temp;
        }
        else
        {
            if (pow > 0)
            {
                return x * temp * temp;
            }
            else
            {
                return (temp * temp) / x;
            }
        }
    }
};