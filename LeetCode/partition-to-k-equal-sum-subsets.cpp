// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
class Solution
{
public:
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {

        // Find the sum of all the items
        int sumOfAllItems = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            sumOfAllItems += nums[i];
        }

        /*
        * We return false if:
        * 1. If the number of subsets <= 0
        * 2. The number of subsets > number of items in the array
        * 3. The total sum of all items needs to be divisible by the
        * number of buckets, otherwise we'd have to fill each bucket
        * with a floating point sum, which is not possible given integer items
        */
        if (k <= 0 || sumOfAllItems % k != 0 || k > nums.size())
        {
            return false;
        }

        vector<bool> used(nums.size(), false);
        return canPartition(0, nums, used, k, 0, sumOfAllItems / k);
    }

    bool canPartition(int iterationStart, vector<int> &nums, vector<bool> &used, int bucketsRemaining, int inProgressBucketSum, int targetSum)
    {

        /*
        * If we have filled all k - 1 buckets up to this point and we are now on
        * our last bucket, we can stop and be finished.
        * Example:
        * arr = [4, 3, 2, 3, 5, 2, 1]
        * k = 4
        * targetBucketSum = 5
        * If we get to the point in our recursion that k = 1 that means we have filled
        * k - 1 buckets (4 - 1 = 3). 3 buckets have been filled, each a value of 5 meaning
        * we have "eaten" 15 "points" of value from an array that sums to 20.
        * This means we have 5 "points" to extract from the array and that for sure will fill
        * the last bucket. So at the point there is 1 bucket left, we know we can complete the
        * partitioning (we don't have to though, we just want to know whether we can or not).
        */
        if (bucketsRemaining == 1)
        {
            return true;
        }

        /*
        * Bucket full. continue the recursion with k - 1 as the new k value, BUT the
        * targetBucketSum stays the same. We just have 1 less bucket to fill.
        */
        if (inProgressBucketSum == targetSum)
        {
            return canPartition(0, nums, used, bucketsRemaining - 1, 0, targetSum);
        }

        for (int i = iterationStart; i < nums.size(); ++i)
        {
            // if the current item hasn't been used, and adding it doesn't exceed the targetSum
            if (!used[i] && inProgressBucketSum + nums[i] <= targetSum)
            {
                used[i] = true;
                // put the item in the bucket and move on to the remaining items
                if (canPartition(i + 1, nums, used, bucketsRemaining, inProgressBucketSum + nums[i], targetSum))
                {
                    return true;
                }
                // reset the used flag back to false if the item didn't work out
                used[i] = false;
            }
        }
        return false;
    }
};