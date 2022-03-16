import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

// https://leetcode.com/problems/strings-differ-by-one-character/

class Solution {
  public boolean differByOne(String[] dict) {
    // Store all combinations of replacements.
    Set<String> set = new HashSet<>();

    // iterate through the list of strings
    for (String s : dict) {
      // iterate over all possible replacements of the string.
      for (String replacement : getReplacements(s)) {
        // if a replacement is already in the set, return true.
        // this means there was already a string in the array
        // that could have been formed by replacing one character in
        // the current string.
        if (!set.add(replacement)) {
          return true;
        }
      }
    }
    return false;
  }

  /**
   * Generates all possible replacements of a string.
   * Converts a string like "abc" to "*bc", "a*c", "ab*".
   * 
   * @param s string to generate replacements for.
   * @return list of all possible replacements.
   */
  List<String> getReplacements(String s) {
    List<String> result = new ArrayList<>(s.length());
    char[] chars = s.toCharArray();
    for (int i = 0; i < s.length(); ++i) {
      char temp = chars[i];
      chars[i] = '*';
      result.add(new String(chars));
      chars[i] = temp;
    }
    return result;
  }
}