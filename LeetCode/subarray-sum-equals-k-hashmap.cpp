// https://leetcode.com/problems/subarray-sum-equals-k/
class Solution {
public:
    int subarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> map;
    int count = 0;
    // maintains sum of elements so far
    int curr_sum = 0;

    // map[0] = 1 helps tackle the case when curr_sum == k
    // because curr_sum - k == 0 in that case, so it helps add that case to solution.
    map[0] = 1;
    for (int num: nums)
    {
        // add the current element to curr_sum
        curr_sum += num;

        // if curr_sum - sum already exists in map
        // we have found a subarray with the target sum
        if (map[curr_sum - k])
        {
            count += map[curr_sum-k];
            // cout << "sum found between " << map[curr_sum - k] + 1 << " and " << i << endl;
        }
        map[curr_sum]++;
    }
    return count;
}
};