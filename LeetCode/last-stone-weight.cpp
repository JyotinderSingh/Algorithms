// https://leetcode.com/problems/last-stone-weight/submissions/
class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> pq;
        for (int num : stones)
        {
            pq.push(num);
        }

        int sum = pq.top();
        pq.pop();
        while (!pq.empty())
        {
            if (sum == pq.top())
            {
                sum = 0;
                pq.pop();
            }
            else
            {
                sum = abs(pq.top() - sum);
                pq.pop();
                pq.push(sum);
            }
            if (!pq.empty())
            {
                sum = pq.top();
                pq.pop();
            }
            else
            {
                return sum;
            }
        }
        return sum;
    }
};