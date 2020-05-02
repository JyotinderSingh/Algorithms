// https://leetcode.com/problems/jewels-and-stones/
class Solution
{
public:
    int numJewelsInStones(string J, string S)
    {
        sort(J.begin(), J.end());
        sort(S.begin(), S.end());

        int count = 0;
        int k = 0;
        for (int j = 0; j < J.size(); ++j)
        {
            for (int i = k; i < S.size(); ++i)
            {
                if (S[i] == J[j])
                {
                    count++;
                    k = i;
                }
            }
        }
        return count;
    }
};