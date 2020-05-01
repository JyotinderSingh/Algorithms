// https://leetcode.com/problems/sort-characters-by-frequency/
class Solution
{
public:
    string frequencySort(string s)
    {
        string res = "";
        unordered_map<char, int> freq;
        for (auto i : s)
        {
            freq[i]++;
        }
        priority_queue<pair<int, char>> pq;
        // by default priority_queue gets sorted acc. to the first element of the pair;
        for (auto iter : freq)
        {
            pq.push({iter.second, iter.first});
        }
        // most frequent elements appear at the top of the pq
        while (!pq.empty())
        {
            // add the top element rep number of times (the number of times it appears in the string)
            int rep = pq.top().first;
            while (rep--)
            {
                res += pq.top().second;
            }
            pq.pop();
        }
        return res;
    }
};