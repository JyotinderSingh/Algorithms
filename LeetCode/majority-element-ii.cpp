// https://leetcode.com/problems/majority-element-ii/
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {

        // Define two majority elements and intialize their counts to 0
        int num1 = -1, num2 = -1, count1 = 0, count2 = 0;

        /*
        * Start scanning the array, and apply a modifies form of the 
        * Boyre Moore algorithm. Here we are keeping track of 2 elements
        * simultaneously. Increasing their count at every match, and decreasing
        * the count at every mismatch.
        */
        for (int i = 0; i < nums.size(); ++i)
        {
            if (num1 == nums[i])
            {
                count1++;
            }
            else if (num2 == nums[i])
            {
                count2++;
            }
            else if (count1 == 0)
            {
                num1 = nums[i];
                count1 = 1;
            }
            else if (count2 == 0)
            {
                num2 = nums[i];
                count2 = 1;
            }
            else
            {
                count1--, count2--;
            }
        }

        vector<int> ans;
        count1 = count2 = 0;
        // We need to verify if both the elements have freq > n/3
        for (int i = 0; i < nums.size(); ++i)
        {
            if (num1 == nums[i])
            {
                count1++;
            }
            else if (num2 == nums[i])
            {
                count2++;
            }
        }
        if (count1 > nums.size() / 3)
        {
            ans.push_back(num1);
        }
        if (count2 > nums.size() / 3)
        {
            ans.push_back(num2);
        }
        return ans;
    }
};

// GENERALIZED SOLUTION FOR N/K MAJORITY ELEMENT
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        return majorityElementK(nums, 3);
    }

    vector<int> majorityElementK(vector<int> &nums, int k)
    {
        vector<int> maj(k - 1, -1);
        vector<int> count(k - 1, 0);

        // Iterate over every element and apply a modified version
        // of Boyre Moore Voting algo - for k elements
        for (auto num : nums)
        {
            // used to indicate if we found an element matching one of our candidate majority elements
            bool find = false;
            // used to indicate if we found an element with count 0, to update the candidate majority element
            bool flag = false;

            // Check candidate majority elements for match
            for (int i = 0; i < maj.size(); ++i)
            {
                if (maj[i] == num)
                {
                    count[i]++;

                    // as we found a match, we don't want to decrease any counts or update any candidates
                    find = true;
                    flag = true;

                    // continue to the next element in the input array
                    break;
                }
            }

            // if no match was found, check if there's any candidates with count 0
            // that can be updated to hold a new element
            if (!find)
            {
                for (int i = 0; i < maj.size(); ++i)
                {
                    if (count[i] == 0)
                    {
                        count[i] = 1;
                        maj[i] = num;

                        // update the flags
                        flag = true;
                        break;
                    }
                }
            }

            // If none of the candidates were updated, decrease the
            // count of each candidate
            if (!flag)
            {
                for (int i = 0; i < count.size(); ++i)
                {
                    count[i]--;
                }
            }
        }

        // Now we want to verify all the final candidates to check if their count > n / 3
        // First reset all counts to 0
        for (auto &x : count)
        {
            x = 0;
        }

        for (auto num : nums)
        {
            for (int i = 0; i < maj.size(); ++i)
            {
                if (maj[i] == num)
                {
                    count[i]++;
                    break;
                }
            }
        }

        vector<int> res;

        for (int i = 0; i < maj.size(); ++i)
        {
            if (count[i] > nums.size() / k)
            {
                res.push_back(maj[i]);
            }
        }
        return res;
    }
};