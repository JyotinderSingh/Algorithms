// https://leetcode.com/problems/happy-number/
class Solution
{
public:
    int digSum(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            int dig = n % 10;
            sum += dig * dig;
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n)
    {
        int slow = n;
        int fast = n;
        while (true)
        {
            slow = digSum(slow);
            if (slow == 1)
            {
                return true;
            }
            fast = digSum(digSum(fast));
            if (fast == 1)
            {
                return true;
            }
            if (slow == fast)
            {
                return false;
            }
        }
    }
};