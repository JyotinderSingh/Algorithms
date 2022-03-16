// https://leetcode.com/problems/implement-strstr/

class Solution {
  public int strStr(String t, String s) {
    if (s.length() > t.length()) {
      return -1;
    }

    int BASE = 256, MOD = 1000000007;
    int powerS = 1; // BASE^|s|
    int tHash = 0, sHash = 0; // hash codes for substrings of t and s.
    // Find hash of s and first s letters of t.
    for (int i = 0; i < s.length(); ++i) {
      powerS = i > 0 ? powerS * BASE : 1;
      tHash = ((tHash * BASE + t.charAt(i) - 'a') % MOD) % MOD; // Double mod to deal with negative modulus.
      sHash = ((sHash * BASE + s.charAt(i) - 'a') % MOD) % MOD; // Double mod to deal with negative modulus.
    }

    // set two pointers,
    // left pointing to start of window and
    // right pointing to next character to be ingested.
    int left = 0, right = s.length();

    while (right < t.length()) {
      // check if hash of current window matches hash of s,
      // and if it does, verify that it is not a collision.
      // Note: substring is exclusive of right index.
      if (tHash == sHash && t.substring(left, right).equals(s)) {
        return left;
      }

      // use rolling hash to compute new hash code.
      tHash -= (t.charAt(left++) - 'a') * powerS;
      tHash = ((tHash * BASE + (t.charAt(right++) - 'a')) % MOD) % MOD; // Double mod to deal with negative modulus.
    }

    // Note: substring is exclusive of right index.
    if (tHash == sHash && t.substring(left, right).equals(s)) {
      return left;
    }

    return -1;
  }
}