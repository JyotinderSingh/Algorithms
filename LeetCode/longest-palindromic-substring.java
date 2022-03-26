// https://leetcode.com/problems/longest-palindromic-substring/

// Manacher's algorithm
class Solution {
  
}

// DP O(N^2) time, O(N^2) space
class Solution {
  public String longestPalindrome(String s) {
    int[][] dp = new int[s.length()][s.length()];
    int resStart = 0, resEnd = 0;

    for (int shift = 0; shift < dp.length; ++shift) {
      for (int i = 0; i + shift < dp.length; ++i) {
        int j = i + shift;

        if (s.charAt(i) == s.charAt(j)) {
          dp[i][j] = (i + 1 >= j - 1) ? 1 : dp[i + 1][j - 1];
          if (dp[i][j] == 1 && (resEnd - resStart + 1) < (j - i + 1)) {
            resStart = i;
            resEnd = j;
          }
        }
      }
    }
    return s.substring(resStart, resEnd + 1);
  }
}