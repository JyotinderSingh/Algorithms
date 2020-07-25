// https://leetcode.com/problems/longest-substring-without-repeating-characters/
// https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems

#define max(a, b) a > b ? a : b

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> hash(128, 0);
        int left = 0, right = 0, res = 0, counter = 0;

        while (right < s.size())
        {
            if (hash[s[right++]]++ > 0)
                counter++;

            while (counter > 0)
            {
                if (hash[s[left++]]-- > 1)
                    counter--;
            }
            res = max(res, right - left);
        }
        return res;
    }
};

//////////////////////////////////////////////////////////////////
////////// EQUIVALENT BUT EASIER TO UNDERSTAND SOLUTION //////////
//////////////////////////////////////////////////////////////////

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> hash(128, 0);
        int res = 0, left = 0, right = 0, counter = 0;

        while (right < s.size())
        {
            // is the count of the current character greater than 0 ?
            // means it has already occurred, and we are facing a duplicate
            if (hash[s[right]] > 0)
            {
                // counter keeps track of the number of duplicates in the current window
                counter++;
            }

            // Add the current character's count to the hash
            hash[s[right]]++;
            // increment the right pointer
            right++;

            // keep shrinking the window until no duplicates are left
            // which will be indicated by the counter becoming 0
            while (counter > 0)
            {
                // if the character being removed (left edge of sliding window) was part of the duplicates
                // (because its count > 1)
                if (hash[s[left]] > 1)
                {
                    // bring down the count of the duplicates
                    counter--;
                }

                // remove the character from the hashmap
                hash[s[left]]--;
                // update left pointer
                left++;
            }

            res = max(res, right - left);
        }
        return res;
    }
};