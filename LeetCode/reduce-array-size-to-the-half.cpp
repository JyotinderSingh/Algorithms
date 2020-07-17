// https://leetcode.com/problems/reduce-array-size-to-the-half/submissions/

class Solution
{
public:
    int minSetSize(vector<int> &arr)
    {
        unordered_map<int, int> freq;

        for (int i = 0; i < arr.size(); ++i)
            freq[arr[i]]++;

        priority_queue<int> pq;

        for (auto iter : freq)
            pq.push(iter.second);

        int count = 0, res = 0;
        while (count * 2 < arr.size())
        {
            res++;
            count += pq.top();
            pq.pop();
        }
        return res;
    }
};