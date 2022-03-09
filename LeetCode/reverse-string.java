// https://leetcode.com/problems/reverse-string/

class Solution {
  public void reverseString(char[] s) {
      int len = s.length;
      for (int i = 0; i < len / 2; ++i) {
          char temp = s[i];
          s[i] = s[len - i - 1];
          s[len - i - 1] = temp;
      }
  }
}