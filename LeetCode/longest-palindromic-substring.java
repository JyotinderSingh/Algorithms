// https://leetcode.com/problems/longest-palindromic-substring/

// O(N^2) time, O(1) space
class Solution {
  public String longestPalindrome(String s) {
    if (s == null || s.length() < 1)
      return "";
    int start = 0, end = 0;

    for (int i = 0; i < s.length(); ++i) {
      int len1 = expandAroundCenter(s, i, i);
      int len2 = expandAroundCenter(s, i, i + 1);
      int len = Math.max(len1, len2);
      if (len > end - start) {
        start = i - (len - 1) / 2;
        end = i + len / 2;
      }
    }
    return s.substring(start, end + 1);
  }

  public int expandAroundCenter(String s, int left, int right) {
    while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
      left--;
      right++;
    }
    return right - left - 1;
  }
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