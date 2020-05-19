// https://leetcode.com/problems/valid-parenthesis-string/


// There is another simple O(n) solution with O(1) space complexity, 
// not very intuitive like the greedy approach, but it's nice to know about it.
// We can rephrase the problem by listing all the valid cases. There are 3 valid cases:

// 1- There are more open parenthesis but we have enough '*' so we can balance the parenthesis with ')'
// 2- There are more close parenthesis but we have enough '*' so we can balance the parenthesis with '('
// 3- There are as many '(' than ')' so all parenthesis are balanced, we can ignore the extra '*'

// Algorithm: You can parse the String twice, once from left to right by replacing all '*' by '(' and 
// once from right to left by replacing all '*' by ')'. For each of the 2 loops, if there's an iteration
// where you end up with a negative count (SUM['('] - SUM[')'] < 0) then you know the parenthesis 
// were not balanced. You can return false. After these 2 checks (2 loops), you know the string 
// is balanced because you've satisfied all the 3 valid cases mentioned above. Voila!



class Solution
{
public:
    bool checkValidString(string s)
    {
        int leftBalance = 0, rightBalance = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(' || s[i] == '*')
            {
                leftBalance++;
            }
            else
            {
                leftBalance--;
            }
            if (leftBalance < 0)
            {
                return false;
            }
        }

        if (leftBalance == 0)
        {
            return true;
        }

        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == ')' || s[i] == '*')
            {
                rightBalance++;
            }
            else
            {
                rightBalance--;
            }

            if (rightBalance < 0)
            {
                return false;
            }
        }

        return true;
    }
};

//////// little Faster but complex ////////////////
//////////// GREEDY //////////////////////////////
class Solution
{
public:
    bool checkValidString(string s)
    {
        int upper = 0, lower = 0;
        for (char i : s)
        {
            if (i == '(')
            {
                lower++, upper++;
            }
            else if (i == ')')
            {
                lower--, upper--;
            }
            else
            {
                lower--, upper++;
            }
            lower = max(lower, 0);
            if (upper < 0)
            {
                return false;
            }
        }
        return lower == 0;
    }
};
