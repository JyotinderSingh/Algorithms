// https://leetcode.com/problems/sliding-window-maximum/
// https://www.youtube.com/watch?v=5VDQxLAlfu0

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> dq;
        vector<int> res;
        res.reserve(nums.size() - k);

        for (int i = 0; i < nums.size(); ++i)
        {
            // remove out of window elements if any
            if (!dq.empty() && dq.front() == i - k)
                dq.pop_front();

            /*
            * remove all elements from the back that are smaller than the
            * current element, to maintain a monotonically decreasing deque.
            *
            * This is because, if the current element is greater than any elements before it,
            * then it'll be the max element in all future windows possible amongst the previous elements
            * that include the previous elements
            */
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            // add the current element to the deque
            dq.push_back(i);

            // add to result for all valid window sizes
            if (i >= k - 1)
                res.push_back(nums[dq.front()]);
        }
        return res;
    }
};

///// SLOWER APPROACH  ///////

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        // ordered multiset to store the items in sorted order
        multiset<int, greater<int>> max;
        vector<int> res;
        int left = 0, right = 0;

        // start sliding window
        while (right < nums.size())
        {
            // insert new element into the multiset
            max.insert(nums[right]);

            // increment right pointer
            right++;

            // if max size of sliding window reached
            if (right - left == k)
            {

                // get max of current window
                res.push_back(*max.begin());

                // remove the leftmost item
                // auto iter = max.find(nums[left]);
                // if (iter != max.end())
                // {
                //     max.erase(iter);
                // }
                max.erase(max.find(nums[left++]));
                left++;
            }
        }
        return res;
    }
};