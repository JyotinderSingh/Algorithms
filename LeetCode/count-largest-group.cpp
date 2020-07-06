// https://leetcode.com/problems/count-largest-group/
class Solution
{
public:
    int countLargestGroup(int n)
    {
        // vector to maintain sizes of each of the groups
        // note that max sum of digits can be for 999 (9 + 9 + 9 = 36)
        vector<int> count(37);
        int max_size = 0;
        int res = 0;
        for (int i = 1; i <= n; ++i)
        {
            max_size = max(max_size, ++count[digSum(i)]);
        }
        for (int i = 0; i < count.size(); ++i)
        {
            if (count[i] == max_size)
                res++;
        }
        return res;
    }

    int digSum(int n)
    {
        int sum = 0;
        while (n)
        {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
};
