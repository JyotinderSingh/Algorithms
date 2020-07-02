// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition
class Solution
{
public:
    int numSubseq(vector<int> &nums, int target)
    {
        const int MOD = 1000000007;
        vector<int> exponents(nums.size() + 1);
        exponents[0] = 1;

        // calculate all the possible expoenents you might need and save them beforehand
        for (int i = 1; i < exponents.size(); ++i)
        {
            exponents[i] = 2 * exponents[i - 1] % MOD;
        }

        // sort the array, helps with the two pointer approach
        // the order of the elements in the subsequence doesn't matter anyway
        // because we are only concerned about the max and min in each of the subseqwuences
        sort(nums.begin(), nums.end());

        int left = 0, right = nums.size() - 1;
        long count = 0;

        while (left <= right)
        {
            if (nums[left] + nums[right] > target)
            {
                right--;
            }
            else
            {

                /*
                * If right - left > 0, the count doesnt consider the rightmost element
                * as an independent subsequence, because it will automatically get counted
                * when left == right.
                * NOTE: The number of subsequences that can be made by x numbers = 2^x
                * (we have two options for each number -> to include it or to leave it)
                */
                long numSubsequences = exponents[right - left];
                count += numSubsequences % MOD;
                left++;
            }
        }
        count %= MOD;
        return (int)count;
    }
};