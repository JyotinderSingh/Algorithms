// https://leetcode.com/problems/add-digits/

class Solution
{
public:
    int addDigits(int num)
    {
        while (num / 10 != 0)
        {
            num = sumDigs(num);
        }
        return num;
    }

    int sumDigs(int num)
    {
        int res = 0;
        while (num)
        {
            res += num % 10;
            num /= 10;
        }
        return res;
    }
};