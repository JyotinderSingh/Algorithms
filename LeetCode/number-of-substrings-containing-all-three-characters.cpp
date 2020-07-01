// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int res = 0;
        vector<int> hash(3, 0);

        int left = 0, right = 0;

        while (right < s.size())
        {
            // add the current character to the frequency table
            hash[s[right] - 'a']++;
            // move the right bound to the right
            right++;

            // while all characters appear at least once
            while (hash[0] > 0 && hash[1] > 0 && hash[2] > 0)
            {
                // the number of substrings containing a,b,c at least once are
                // equal to all the substrings from lo to hi, hi + 1, hi + 2..... s.size() - 1
                res += s.size() - right + 1;

                /*
                * move the left pointer to the right, to shrink from the left
                * and check again if the condition is still satisfied, else continue with the outer
                * while loop and inrement right pointer to explore further.
                * Also decrement the frequency of the leftmost character in the window, as we are
                * leaving it behind.
                */
                hash[s[left] - 'a']--;
                left++;
            }
        }

        return res;
    }
};

////////////////////////////////////////////
//// MINIFIED BUT LESS READABLE VERSION ////
////////////////////////////////////////////

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int res = 0;
        vector<int> hash(3, 0);

        int left = 0, right = 0;

        while (right < s.size())
        {
            hash[s[right++] - 'a']++;

            while (hash[0] > 0 && hash[1] > 0 && hash[2] > 0)
            {
                res += s.size() - right + 1;
                hash[s[left++] - 'a']--;
            }
        }

        return res;
    }
};