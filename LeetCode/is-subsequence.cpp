// https://leetcode.com/problems/is-subsequence/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        for(const auto& ch: t) {
            if(ch == s[i]) {
                i++;
            }
        }
        return i == s.size();
    }
};