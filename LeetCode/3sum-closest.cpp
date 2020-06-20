    // https://leetcode.com/problems/3sum-closest/
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int minDiff = INT_MAX;
        int minSum = INT_MAX;
        for (int i = 0; i < nums.size() - 2; ++i)
        {
            int front = i + 1;
            int rear = nums.size() - 1;
            while (front < rear)
            {
                int sum = nums[i] + nums[front] + nums[rear];
                if (sum == target)
                {
                    return sum;
                }
                int currDiff = abs(target - sum);
                if (currDiff < minDiff)
                {
                    minDiff = currDiff;
                    minSum = sum;
                }
                else if (target > sum)
                {
                    front++;
                }
                else
                {
                    rear--;
                }
            }
        }
        return minSum;
    }
};