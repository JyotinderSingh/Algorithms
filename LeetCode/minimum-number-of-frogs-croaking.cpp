// https://leetcode.com/problems/minimum-number-of-frogs-croaking/submissions/
class Solution
{
public:
    int minNumberOfFrogs(string croakOfFrogs)
    {
        int frogs = 0, max_frogs = 0;
        int croak[5] = {};
        for (auto c : croakOfFrogs)
        {
            int n = string("croak").find(c);
            ++croak[n];
            if (n == 0)
            {
                ++frogs;
                //if a frog has completed the croak, the same one can start again (as we need min number of frogs)
                max_frogs = max(max_frogs, frogs);
            }
            else if (--croak[n - 1] < 0)
            {
                // if some misplaced character is there, i.e. the preceding letter isnt available
                return -1;
            }
            else if (n == 4)
            {
                // decrease the temp counter once the croak is complete
                // it was already logged in the max_frogs
                --frogs;
            }
        }
        // if frogs != 0, then some frog was in the middle of a croak and didn't complete.
        return frogs == 0 ? max_frogs : -1;
    }
};