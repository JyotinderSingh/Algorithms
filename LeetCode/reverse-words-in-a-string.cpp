// https://leetcode.com/problems/reverse-words-in-a-string/

class Solution
{
public:
    string reverseWords(string s)
    {
        string res;
        if (!s.size())
            return res;
        int i = 0, j = s.size() - 1;
        while (s[i] == ' ' && i <= j)
            i++;
        while (s[j] == ' ' && j >= i)
            j--;
        for (; j >= i; --j)
        {
            if (s[j] == ' ')
            {
                while (j > 0 && s[j - 1] == ' ')
                {
                    j--;
                }
            }
            res += s[j];
        }

        int start = 0, end;
        while ((end = res.find(" ", start)) != string::npos)
        {
            reverse(res.begin() + start, res.begin() + end);
            start = end + 1;
        }

        reverse(res.begin() + start, res.end());

        return res;
    }
};

///////////////////////////////////////////////////

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