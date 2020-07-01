// https://leetcode.com/problems/kth-largest-element-in-an-array/
// https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/60309/C%2B%2B-STL-partition-and-heapsort

// MAX HEAP
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int> pq(nums.begin(), nums.end());
        // here we basically removed the k - 1 larger elements
        while (k-- > 1)
        {
            pq.pop();
        }
        return pq.top();
    }
};

// MIN HEAP
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < nums.size(); ++i)
        {
            pq.push(nums[i]);
            // here we only let the largest k elements of the array
            // remain in the heap, as we're removing all the smallest ones
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        // only k largest elements of the array remain
        // and the smallest of those will be the kth largest
        return pq.top();
    }
};