// https://leetcode.com/problems/container-with-most-water/
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int front = 0, rear = height.size() - 1;
        int max_volume = 0;
        while (front < rear)
        {
            max_volume = max(max_volume, min(height[front], height[rear]) * (rear - front));
            if (height[front] < height[rear])
            {
                front++;
            }
            else
            {
                rear--;
            }
        }
        return max_volume;
    }
};