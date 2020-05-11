// https://leetcode.com/problems/4sum/
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> res;
        if (nums.size() < 4)
        {
            return res;
        }

        /*
        * Sorting the array makes the solution a lot simpler
        * The answer would anyway would've been ~ O(n^3) so
        * the nlogn addition to it wouldnt make a difference
        */
        sort(nums.begin(), nums.end());

        int n = nums.size();

        for (int i = 0; i < n - 3; ++i)
        {

            // Skip the same values of i, as duplicate sets aren't allowed in res
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            /*
            * The array is sorted in ascending order, hence this is the smallest
            * sum that can be achieved with the current value of i. If this is greater
            * than the target then no other solution sets remain in the solution space.
            */
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
            {
                break;
            }

            /*
            * This is the maximum sum that can be achieved with the current
            * value of i, if this is smaller than the target, go to the next value
            * of i (which would be bigger than the current one as array is sorted)
            */
            if (nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3] < target)
            {
                continue;
            }

            for (int j = i + 1; j < n - 2; ++j)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }

                /*
                * The array is sorted in ascending order, hence this is the smallest
                * sum that can be achieved with the current value of i & j. If this is greater
                * than the target then no other solution sets remain in the solution space.
                */
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
                {
                    break;
                }

                /*
                * This is the maximum sum that can be achieved with the current
                * value of i & j, if this is smaller than the target, go to the next value
                * of i (which would be bigger than the current one as array is sorted)
                */
                if (nums[i] + nums[j] + nums[n - 1] + nums[n - 2] < target)
                {
                    continue;
                }

                int front = j + 1;
                int rear = n - 1;

                while (front < rear)
                {
                    int sum = nums[i] + nums[j] + nums[front] + nums[rear];

                    if (sum == target)
                    {
                        res.push_back({nums[i], nums[j], nums[front], nums[rear]});

                        // skip all duplicate values of nums[front]
                        while (front < rear && nums[front] == nums[front + 1])
                        {
                            front++;
                        }

                        // skip all duplicate values of nums[rear]
                        while (rear > front && nums[rear] == nums[rear - 1])
                        {
                            rear--;
                        }

                        // increment them to the next unique value finally
                        front++, rear--;
                    }
                    else if (sum < target)
                    {
                        // sum was too small, move front to the right
                        front++;
                    }
                    else
                    {
                        // sum was too big, move rear to the left
                        rear--;
                    }
                }
            }
        }
        return res;
    }
};>