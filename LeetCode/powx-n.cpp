// https://leetcode.com/problems/powx-n/submissions/
// https://www.youtube.com/watch?v=wAyrtLAeWvI

class Solution
{
public:
    double myPow(double x, long long int n)
    {
        if (n == 0)
            return 1;
        if (n < 0)
        {
            return myPow(1 / x, -n);
        }
        else
        {
            if (n % 2 == 0)
            {
                auto y = myPow(x, n / 2);
                return y * y;
            }
            else
            {
                return x * myPow(x, n - 1);
            }
        }
    }
};

////////////////////////////////////////////////////////////////

class Solution
{
public:
    double myPow(double x, int n)
    {
        return powFunc(x, n);
    }

    double powFunc(double x, long long int n)
    {
        if (n == 0)
            return 1;
        if (n < 0)
        {
            return powFunc(1 / x, -n);
        }
        else
        {
            if (n % 2 == 0)
            {
                auto y = powFunc(x, n / 2);
                return y * y;
            }
            else
            {
                return x * powFunc(x, n - 1);
            }
        }
    }
};