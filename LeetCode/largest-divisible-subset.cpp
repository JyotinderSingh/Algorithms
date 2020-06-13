// https://leetcode.com/problems/largest-divisible-subset/
class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        vector<int> res;
        if (!nums.size())
        {
            return res;
        }
        sort(nums.begin(), nums.end());

        // count[i] represents count of numbers in the subset with largest element as i
        vector<int> count(nums.size(), 1);
        int max_count_index = 0, max_count = 0;
        // parent[i] keeps track of the parent (the number that divides the i'th number) of the i'th element
        vector<int> parent(nums.size(), -1);

        // Similar to Longest Increasing Subsequence
        // Bottom Up approach
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                // Check if this qualifies to be in the subset and beats the current best score
                if (nums[i] % nums[j] == 0 && count[i] < count[j] + 1)
                {
                    count[i] = count[j] + 1;
                    parent[i] = j;
                }
            }
            if (count[i] > max_count)
            {
                max_count = count[i];
                max_count_index = i;
            }
        }

        res.reserve(max_count);

        while (max_count_index != -1)
        {
            res.push_back(nums[max_count_index]);
            max_count_index = parent[max_count_index];
        }
        return res;
    }
};

////////////////////////////////////////
//////// SLOWER BUT EASIER /////////////
////////////////////////////////////////
class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        vector<int> res;
        if (!nums.size())
        {
            return res;
        }
        sort(nums.begin(), nums.end());

        vector<int> count(nums.size());
        int max_count_index = 0;

        // Similar to Longest Increasing Subsequence
        for (int i = 0; i < count.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                // Check if this qualifies to be in the subset
                if (nums[i] % nums[j] == 0)
                {
                    // If it qualifies, check if it beats the current best
                    // score (if counting this subset adds more elements than already found)
                    count[i] = max(count[i], count[j] + 1);
                }
                max_count_index = count[i] > count[max_count_index] ? i : max_count_index;
            }
        }
        int curr_count = count[max_count_index];
        res.reserve(count[max_count_index]);
        for (int i = max_count_index; i >= 0; --i)
        {
            if (nums[max_count_index] % nums[i] == 0 && count[i] == curr_count)
            {
                res.push_back(nums[i]);
                curr_count--;
            }
        }
        return res;
    }
};