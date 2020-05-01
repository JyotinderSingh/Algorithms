// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        priority_queue<int> max_heap;
        for (auto row : matrix)
        {
            for (auto ele : row)
            {
                if (max_heap.size() < k)
                {
                    max_heap.push(ele);
                }
                else
                {
                    // if size of heap == k
                    // check if cuurent element being scanned is smaller than top element
                    // if yes, then the top element is to be removed as it is one of the top k largest elements
                    // else we just need to add and remove the current element being scanned i.e. do nothing.
                    if (ele < max_heap.top())
                    {
                        max_heap.pop();
                        max_heap.push(ele);
                    }
                }
            }
        }
        return max_heap.top();
    }
};