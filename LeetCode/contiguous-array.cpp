// https://leetcode.com/problems/contiguous-array/
class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        //      sub array [A,B] = prefix[B] - prefix[A-1];
        unordered_map<int, int> mp;
        int longestContArray = 0;
        int sum = 0;
        mp.insert({0, -1}); // allows you to find total number of elements by using prefix method, you don't need to add extra if condition for                             // 0 sum condition
        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i] == 0 ? -1 : 1;

            if (mp.find(sum) != mp.end())
            {
                longestContArray = max(longestContArray, i - mp[sum]);
            }
            else
            {
                mp.insert({sum, i});
            }
        }
        return longestContArray;
    }
};










// Solution below uses the same approach as above,
// while being a little more clear by using a few extra if statements
// class Solution
// {
// public:
//     int findMaxLength(vector<int> &nums)
//     {
//         //      sub array [A,B] = prefix[B] - prefix[A-1];
//         unordered_map<int, int> mp;
//         int longestContArray = 0;
//         int sum = 0;
//         for (int i = 0; i < nums.size(); ++i)
//         {
//             sum += nums[i] == 0 ? -1 : 1;

//             auto it = mp.find(sum);

//             if (sum == 0)
//             {
//                 longestContArray = max(longestContArray, i + 1);
//             }
//             else if (it != mp.end())
//             {
//                 longestContArray = max(longestContArray, i - mp[sum]);
//             }
//             else
//             {
//                 mp.insert({sum, i});
//             }
//         }
//         return longestContArray;
//     }
// };