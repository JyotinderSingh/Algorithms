// https://leetcode.com/problems/top-k-frequent-elements/
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> res;
        unordered_map<int, int> frequency;
        for (auto num : nums)
        {
            frequency[num]++;
        }
        // frequency is of structure <element, frequency>
        // we push it into the heap in the form a pair<frequency, element>
        priority_queue<pair<int, int>> pq;
        for (auto iter = frequency.begin(); iter != frequency.end(); ++iter)
        {
            pq.push(make_pair(iter->second, iter->first));
        }
        while (pq.size() > frequency.size() - k)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};