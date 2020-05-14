// https://leetcode.com/problems/ugly-number-ii/
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        if (n == 1)
        {
            return 1;
        }

        vector<int> ugly(n);
        ugly[0] = 1;

        int n1 = 0, n2 = 0, n3 = 0;

        for (int i = 1; i < n; ++i)
        {
            int next = min({2 * ugly[n1], 3 * ugly[n2], 5 * ugly[n3]});

            if (next == 2 * ugly[n1])
            {
                n1++;
            }
            if (next == 3 * ugly[n2])
            {
                n2++;
            }
            if (next == 5 * ugly[n3])
            {
                n3++;
            }

            ugly[i] = next;
        }
        return ugly[n - 1];
    }
};