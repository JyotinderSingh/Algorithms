// https://leetcode.com/problems/is-subsequence/

class Solution {
  public boolean isSubsequence(String substring, String t) {
    if (substring.length() == 0) {
      return true;
    }

    int i = 0;
    for (char ch : t.toCharArray()) {
      if (ch == substring.charAt(i)) {
        i++;

        if (i == substring.length()) {
          return true;
        }
      }
    }

    return false;
  }
}