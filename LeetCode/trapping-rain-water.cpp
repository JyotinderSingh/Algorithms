// https://leetcode.com/problems/trapping-rain-water/
// https://www.youtube.com/watch?v=XqTBrQYYUcc&t=339s

// O(N) time and O(1) space
class Solution
{
public:
    int trap(vector<int> &height)
    {
        if (!height.size())
        {
            return 0;
        }

        /*
        * Lower Envelope Technique
        * Takes advantage of the fact that the leftMax and rightMax
        * functions are monotonic
        */
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int ans = 0;
        while (left < right)
        {
            if (height[left] > leftMax)
            {
                leftMax = height[left];
            }
            if (height[right] > rightMax)
            {
                rightMax = height[right];
            }
            if (leftMax < rightMax)
            {
                ans += leftMax - height[left];
                // since we've calculated the ans for this cell, we move ahead
                left++;
            }
            else
            {
                ans += rightMax - height[right];
                // since we've calculated the ans for this cell, we move back
                right--;
            }
        }
        return ans;
    }
};

//////////////////////////////////////

// O(N) time and O(N) space
class Solution
{
public:
    int trap(vector<int> &height)
    {
        if (!height.size())
        {
            return 0;
        }
        // Keeps track of the max height pillar on left of current elementc
        vector<int> maxOnLeft(height.size(), 0);
        // Keeps track of the max height pillar on right of current elementc
        vector<int> maxOnRight(height.size(), 0);

        maxOnLeft[0] = height[0];
        for (int i = 1; i < maxOnLeft.size(); ++i)
        {
            maxOnLeft[i] = max(height[i], maxOnLeft[i - 1]);
        }

        maxOnRight[height.size() - 1] = height[height.size() - 1];
        for (int i = height.size() - 2; i >= 0; --i)
        {
            maxOnRight[i] = max(height[i], maxOnRight[i + 1]);
        }

        int volume = 0;

        // The amount of water trapper on a cell i => min(maxOnLeft[i], maxOnRight[i]) - height[i]
        for (int i = 0; i < height.size(); ++i)
        {
            volume += min(maxOnLeft[i], maxOnRight[i]) - height[i];
        }

        return volume;
    }
};