// https://leetcode.com/problems/longest-palindromic-substring/
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int longestLength = 0;
        int longestPalindromeStart = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            // len1 is the length of the palindrome when we assume odd number of
            // characters in the palindrome
            // something like "aba", "racecar"
            //                  |        |
            // where there will be no matching pair for the middle element
            int len1 = checkPalindromeLength(s, i, i);

            // len2 is the length o the palindrome when we assume even number of
            // characters in the palindrome
            // something like "abba"
            int len2 = checkPalindromeLength(s, i, i + 1);

            int len = max(len1, len2);
            if (longestLength < len)
            {
                // we get the start of the palindrome by subtracting half the length from the middle index
                // we subtract 1 from len when dividing by two to manage the boundary condition
                longestPalindromeStart = i - (len - 1) / 2;
                longestLength = len;
            }
        }
        return s.substr(longestPalindromeStart, longestLength);
    }

    int checkPalindromeLength(const string &s, int left, int right)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--, right++;
        }
        // we reset the left and right to the last valid indices
        // before they violated the while loop condition
        left++, right--;
        // returns the length of the palindrome that can be formed starting from these indices
        return right - left + 1;
    }
};