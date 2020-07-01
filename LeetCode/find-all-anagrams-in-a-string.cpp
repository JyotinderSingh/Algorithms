// https://leetcode.com/problems/find-all-anagrams-in-a-string/
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> res;
        if (p.size() > s.size())
        {
            return res;
        }
        vector<int> hash(256, 0);

        // record each character in p to hash
        for (int i = 0; i < p.size(); ++i)
        {
            hash[p[i]]++;
        }

        // two points, initialize count to p's length
        int left = 0, right = 0, count = p.size();
        while (right < s.size())
        {

            /*
            * move one step to the right at each iteration
            * if the character exists in p's hash, decrease the count.
            * current hash value >= 1 means the character is existing in p
            * Note that we are using POST increment/decrement operations
            */
            if (hash[s[right++]]-- >= 1)
            {
                count--;
            }

            /*
            * If the count == 0, means all characters have been matched
            * hence an anagram has been found
            * Add the left index to the result array
            */
            if (count == 0)
            {
                res.push_back(left);
            }

            /*
            * if we find the window's size equals to that of p, 
            * then we have to move left (narrow the window) to find the new match window
            * ++ to reset the hash because we had subtracted the left element from the hash
            * only increase the count if the character was found in p
            * the count >= 0 indicates that it was in original in the hash, because it didn't go below 0
            * (Had the character not been in the hash, the count of that element would'vee gone below 0)
            */
            if (right - left == p.size() && hash[s[left++]]++ >= 0)
            {
                count++;
            }
        }

        return res;
    }
};

/////////////////////////////////////////////////////
//////////// MORE READABLE SOLUTION /////////////////

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> res;

        // If the size of the substring is greater than
        // the given string, return empty array
        if (p.size() > s.size())
            return res;

        // create a hashmap to keep track of the characters in the substring
        vector<int> hash(256, 0);
        for (int i = 0; i < p.size(); ++i)
            hash[p[i]]++;

        int left = 0, right = 0, count = p.size();

        // Iterate through the givene string
        while (right < s.size())
        {
            // If the current character being scanned occured in p, decrease count
            if (hash[s[right]] >= 1)
            {
                count--;
            }
            // decrease the frequency of the current character in the hashmap as you encounter it
            hash[s[right]]--;
            // move the right bound
            right++;

            // If count == 0, means you found all the characters of p in current substring
            if (count == 0)
            {
                res.push_back(left);
            }

            // If the substring is of the size of p
            if (right - left == p.size())
            {
                // if the current character's frequency >=0, it means it occured in p as well
                // hence now that you are leaving it behind, add back its count to the count variable
                if (hash[s[left]] >= 0)
                {
                    count++;
                }
                // increase it's frequency back in the hashmap also
                hash[s[left]]++;
                // move the left bound towards the right
                left++;
            }
        }
        return res;
    }
};