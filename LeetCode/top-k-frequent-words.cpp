// https://leetcode.com/problems/top-k-frequent-words/
class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        vector<string> res;
        unordered_map<string, int> freq;
        for (auto w : words)
        {
            freq[w]++;
        }

        // we define a priority queue of type priority_queue<pair<string, frequency>> which uses a custom comparator
        // by default the PQ compares acc. to the first element of the pair.
        // but we're given an extra condition that if the frequencies of two strings
        // are the same, we're supposed to sort them on the basis of their alphabetical ordering
        // with the element appearing first in the alphabet on the top.

        // below is the custom comaparator
        // remember: comparators always return inverse of how you wanna compare
        auto comp = [&](const pair<string, int> &a, const pair<string, int> &b) {
            return (a.second < b.second) || (a.second == b.second && a.first > b.first);
        };

        // declaring the priority queue
        // decltype extracts the return type from the function and passes it to the contructor
        typedef priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comp)> my_pq;
        my_pq pq(comp);
        // or
        // priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comp)> pq(comp);

        for (auto iter : freq)
        {
            pq.push({iter.first, iter.second});
        }

        while (k--)
        {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};