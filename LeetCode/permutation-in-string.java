// https://leetcode.com/problems/permutation-in-string/

class Solution {
  public boolean checkInclusion(String s1, String s2) {
    if (s1.length() > s2.length())
      return false;

    int[] s1map = new int[26];
    int[] s2map = new int[26];

    for (int i = 0; i < s1.length(); ++i) {
      s1map[s1.charAt(i) - 'a']++;
      s2map[s2.charAt(i) - 'a']++;
    }

    int count = 0;
    for (int i = 0; i < 26; ++i) {
      if (s1map[i] == s2map[i]) {
        count++;
      }
    }

    for (int i = 0; i < s2.length() - s1.length(); ++i) {
      if (count == 26)
        return true;

      int outgoing = s2.charAt(i) - 'a', incoming = s2.charAt(i + s1.length()) - 'a';
      s2map[incoming]++;

      // addition of new element caused match
      if (s2map[incoming] == s1map[incoming])
        count++;
      // addition of new element caused mismatch
      else if (s2map[incoming] == s1map[incoming] + 1)
        count--;

      // decrease outgoing element's frequency
      s2map[outgoing]--;
      // if the removal caused a match to occur, increase count
      if (s2map[outgoing] == s1map[outgoing])
        count++;
      // if removal caused a mismatch to occur, decrease count
      else if (s2map[outgoing] == s1map[outgoing] - 1)
        count--;
    }

    return count == 26;
  }
}