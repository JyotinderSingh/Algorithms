// https://www.youtube.com/watch?v=GU7DpgHINWQ&t=882s
#include <iostream>
using namespace std;

double root(double n, double prec)
{
    double left = 0, right = n;
    while (right - left > prec)
    {
        double mid = left + (right - mid) / 2;
        if (mid * mid < n)
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }
    return left + (right - left) / 2;
}

int main()
{
    cout << root(5, 0.00001);
}