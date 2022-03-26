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

// Method 2
// https://www.youtube.com/watch?v=_nCsPn7_OgI

class Solution {
  public int longestPalindromeSubseq(String s) {
    int[][] dp = new int[s.length()][s.length()];

    for (int shift = 0; shift < dp.length; ++shift) {
      for (int i = 0; i + shift < dp.length; ++i) {
        int j = i + shift;

        // Here i and j are the left and right index of the subsequence
        // of the string being considered
        if (s.charAt(i) == s.charAt(j)) {
          // 1. if i == j, then simply put 1, as window is 1 char long
          // 2. in other cases, add 2 to the maxlen for the substring
          // contained inside s[i] and s[j] (exclusive).
          dp[i][j] = (i == j) ? 1 : 2 + dp[i + 1][j - 1];
        } else {
          // if s[i] != s[j], max length of palindromic subsequence
          // for the current window will be the same as that for the
          // substring contained inside s[i] and s[j]
          dp[i][j] = Math.max(dp[i + 1][j], dp[i][j - 1]);
        }
      }
    }
    return dp[0][dp[0].length - 1];
  }
}