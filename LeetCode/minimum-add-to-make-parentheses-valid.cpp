// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
class Solution
{
public:
    int minAddToMakeValid(string S)
    {
        int ans = 0, balance = 0;
        for (int i = 0; i < S.size(); ++i)
        {
            balance += S[i] == '(' ? 1 : -1;
            if (balance == -1)
            {
                ans++; // keeps track of extra ')' for which a '(' needs to be added
                balance++;
            }
        }

        // if balance > 0, it means those many '(' were extra, and corrosponding ')' need to be added
        return ans + balance;
    }
};