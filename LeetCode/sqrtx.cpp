// https://leetcode.com/problems/sqrtx/
class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0 || x == 1)
        {
            return x;
        }

        // BINARY SEARCH
        long front = 0, rear = x;
        long mid, sq;
        while (front <= rear)
        {
            mid = front + (rear - front) / 2;
            sq = mid * mid;
            if (sq == x)
            {
                return mid;
            }
            else if (sq < x)
            {
                front = mid + 1;
            }
            else
            {
                rear = mid - 1;
            }
        }
        if (x > sq)
        {
            return mid;
        }
        return mid - 1;
    }
};