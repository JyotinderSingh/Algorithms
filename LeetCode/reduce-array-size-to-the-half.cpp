// https://leetcode.com/problems/reduce-array-size-to-the-half/submissions/

class Solution
{
public:
    int minSetSize(vector<int> &arr)
    {
        unordered_map<int, int> um;
        //  count the frequencies
        for (int i : arr)
        {
            um[i]++;
        }

        unordered_map<int, int>::iterator itr;
        int count = 0, sum = 0;
        vector<int> v;
        // add all frequencies into a vector
        for (itr = um.begin(); itr != um.end(); ++itr)
        {
            v.push_back(itr->second);
        }
        // sort the vector in descending order
        sort(v.begin(), v.end(), greater<int>());

        // start adding up frequencies till they add up to the threshold
        for (int i : v)
        {
            count++;
            sum += i;
            if (sum >= arr.size() / 2)
            {
                return count;
            }
        }
        return count;
    }
};