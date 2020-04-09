// https://leetcode.com/problems/reverse-words-in-a-string/submissions/
class Solution
{
public:
    string reverseWords(string s)
    {
        reverse(s.begin(), s.end());
        s.erase(0, s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);

        int write_index = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == ' ')
            {
                continue;
            }
            if (write_index != 0)
            {
                s[write_index++] = ' ';
            }

            int j = i;
            while (j < s.size() && s[j] != ' ')
            {
                s[write_index++] = s[j++];
            }
            reverse(s.begin() + write_index - (j - i), s.begin() + write_index);

            i = j;
        }
        s[write_index] = '\0';
        return s;
    }
};