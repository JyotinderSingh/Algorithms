// https://leetcode.com/problems/bulb-switcher-iii/
class Solution
{
public:
    int numTimesAllBlue(vector<int> &light)
    {
        int rightMostBulb = 0, ctr = 0;
        for (int i = 0; i < light.size(); ++i)
        {
            rightMostBulb = max(rightMostBulb, light[i]);
            // when number of bulbs switched on (i + 1) is
            // equal to the position of the rightmost bulb
            // it means all bulbs to it's left are switched on
            // so increment counter
            if (i + 1 == rightMostBulb)
            {
                ctr++;
            }
        }
        return ctr;
    }
};

///// SLOWER SOLUTION/////

class Solution
{
public:
    int numTimesAllBlue(vector<int> &light)
    {
        long long int sum = 0;
        long long int count = 0;
        for (long long int i = 0; i < light.size(); ++i)
        {
            sum += light[i];
            if (sum == (i + 1) * (i + 2) / 2)
            {
                count++;
            }
        }
        return count;
    }
};
