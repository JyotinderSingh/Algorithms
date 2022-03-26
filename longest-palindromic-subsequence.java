// https://leetcode.com/problems/longest-palindromic-subsequence/

// You can basically consider this problem to be the same as 
// Longest Common Subsequence between String s1 and another string s2, where
// s2 is reverse of s1.
// https://www.youtube.com/watch?v=wuOOOATz_IA

class Solution {
  public int longestPalindromeSubseq(String s) {
    int[][] dp = new int[s.length() + 1][s.length() + 1];

    String s2 = new StringBuilder(s).reverse().toString();

    // Solve this like Longest Common subsequence between the string the reverse
    // of that same string.
    for (int i = 1; i < dp.length; ++i) {
      for (int j = 1; j < dp[0].length; ++j) {
        if (s.charAt(i - 1) == s2.charAt(j - 1)) {
          dp[i][j] = 1 + dp[i - 1][j - 1];
        } else {
          dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
    return dp[dp.length - 1][dp[0].length - 1];
  }
}