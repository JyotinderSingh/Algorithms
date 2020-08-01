// https://leetcode.com/problems/decode-ways/

class Solution
{
public:
    int numDecodings(string s)
    {
        // will memoize each position of the string for the decodings that you can build there
        vector<int> dp(s.size(), -1);
        return numDecodings(s, 0, dp);
    }

    int numDecodings(const string &s, int decodePtr, vector<int> &dp)
    {
        if (decodePtr >= s.size())
        {
            // "" is a valid decoding
            return 1;
        }

        // Subproblem already solved and has a value
        if (dp[decodePtr] > -1)
        {
            return dp[decodePtr];
        }

        int totalDecompositions = 0;

        for (int i = 1; i <= 2; ++i)
        {
            if (decodePtr + i <= s.size())
            {
                string snippet = s.substr(decodePtr, i);
                if (isValid(snippet))
                {
                    totalDecompositions += numDecodings(s, decodePtr + i, dp);
                }
            }
        }

        // Record subproblem answer to decompositions from (decodePointer)...(s.length - 1)
        dp[decodePtr] = totalDecompositions;

        return totalDecompositions;
    }

    bool isValid(string snippet)
    {
        if (snippet[0] == '0')
        {
            return false;
        }

        int value = stoi(snippet);
        return value >= 1 && value <= 26;
    }
};