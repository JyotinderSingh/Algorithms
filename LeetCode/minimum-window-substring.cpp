// https://leetcode.com/problems/minimum-window-substring/
// https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems

class Solution
{
public:
    string minWindow(string s, string t)
    {
        string res;
        vector<int> hash(128, 0);

        // Build a map for string t
        for (int i = 0; i < t.size(); ++i)
            hash[t[i]]++;
        int left = 0, right = 0, count = t.size(), head = 0, d = INT_MAX;

        while (right < s.size())
        {
            if (hash[s[right++]]-- >= 1)
                count--;

            while (count == 0)
            {
                if (right - left < d)
                {
                    // don't need to do right - left + 1, as right was already incremented past it's current position
                    d = right - left;
                    head = left;
                }
                if (hash[s[left++]]++ >= 0)
                    count++;
            }
        }
        return d == INT_MAX ? "" : s.substr(head, d);
    }
};

////////////////////////////////////////////////////////////
/////// EQUIVALENT BUT EASIER TO UNDERSTAND SOLUTION ///////
////////////////////////////////////////////////////////////

class Solution
{
public:
    string minWindow(string s, string t)
    {
        vector<int> hash(128, 0);
        int left = 0, right = 0, head = 0, d = INT_MAX, counter = t.size();

        // Add the characters of t to the hashmap
        for (int i = 0; i < t.size(); ++i)
            hash[t[i]]++;

        while (right < s.size())
        {
            // if this character is a part of t
            if (hash[s[right]] > 0)
            {
                // decrease the counter
                counter--;
            }

            // remove its count from the hashtable
            hash[s[right]]--;
            // update the right pointer
            right++;

            // shrink the window while it remains valid
            while (counter == 0)
            {

                // see if the window size is better than the current best
                if (right - left < d)
                {
                    d = right - left;
                    head = left;
                }

                // can only be 0 if this existed in t, otherwise would've been negative
                if (hash[s[left]] == 0)
                {
                    // add it back to the counter
                    counter++;
                }
                // Add the count back to the hashtable
                hash[s[left]]++;
                // update the left pointer
                left++;
            }
        }
        return d == INT_MAX ? "" : s.substr(head, d);
    }
};