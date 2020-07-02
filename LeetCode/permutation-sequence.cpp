// https://leetcode.com/problems/permutation-sequence/
// https://leetcode.com/problems/permutation-sequence/discuss/22507/%22Explain-like-I'm-five%22-Java-Solution-in-O(n)
class Solution
{
public:
    string getPermutation(int n, int k)
    {
        string res = "";
        vector<int> fact(n + 1);
        fact[0] = 1;

        // Keep track of all the factorial values you'll need
        for (int i = 1; i < fact.size(); ++i)
        {
            fact[i] = i * fact[i - 1];
        }

        // Create a vector of all the numbers to be used
        vector<int> nums(n);
        for (int i = 0; i < n; ++i)
            nums[i] = i + 1;

        // As indices begin from 0, we just decrease k by 1, to adjust k accordingly
        k--;

        // Start going through all the n iterations
        for (int i = 1; i <= n; ++i)
        {

            // index = (permutation number) / (number of permutations of the remaining elements, when you fix i'th element)
            int index = k / fact[n - i];

            // Add the number at the resulting index to the result
            res += to_string(nums[index]);

            // Remove the selected number from the set
            nums.erase(nums.begin() + index);

            // subtract the number of permutations that you've covered by fixing the current element
            // k = k - ((index of current element) * (number of permutations in remaining elements))
            k -= index * fact[n - i];
        }
        return res;
    }
};
