// https://leetcode.com/problems/substrings-that-begin-and-end-with-the-same-letter/
// https://leetcode.com/problems/substrings-that-begin-and-end-with-the-same-letter/discuss/1669285/Java-single-pass-with-constant-space

class Solution {
  public long numberOfSubstrings(String s) {
    // Keep track of frequency
    int[] arr = new int[26];
    long res = 0;

    for (char ch : s.toCharArray()) {
      res += ++arr[ch - 'a'];
    }

    return res;
  }
}