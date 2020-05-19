// https://leetcode.com/problems/permutation-in-string/
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        vector<int> hash(256, 0);
        if (s1.size() > s2.size())
        {
            return false;
        }

        for (int i = 0; i < s1.size(); ++i)
        {
            hash[s1[i]]++;
        }

        int left = 0, right = 0, counter = s1.size();

        while (right < s2.size())
        {
            if (hash[s2[right++]]-- >= 1)
            {
                counter--;
            }

            if (counter == 0)
            {
                return true;
            }

            if (right - left == s1.size() && hash[s2[left++]]++ >= 0)
            {
                counter++;
            }
        }
        return false;
    }
};