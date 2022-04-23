// https://leetcode.com/problems/guess-the-word/
// https://leetcode.com/problems/guess-the-word/discuss/1394280/Java-Minimax-Solution-Explained-in-depth!

import java.util.HashMap;

/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface Master {
 * public int guess(String word) {}
 * }
 */
class Solution {
  public void findSecretWord(String[] wordlist, Master master) {
    // Maintains the mapping from a word to the number of other words it has
    // any number of letter matches with.
    HashMap<String, Integer> matchCount = new HashMap<>();

    // Check the matches between every pair for word in the list
    for (int i = 0; i < wordlist.length; ++i) {
      for (int j = i + 1; j < wordlist.length; ++j) {
        String word1 = wordlist[i];
        String word2 = wordlist[j];

        if (!matchCount.containsKey(word1))
          matchCount.put(word1, 0);
        if (!matchCount.containsKey(word2))
          matchCount.put(word2, 0);

        // if the two words have any matches increment their counters.
        if (compareStrings(word1, word2) > 0) {
          matchCount.put(word1, matchCount.get(word1) + 1);
          matchCount.put(word2, matchCount.get(word2) + 1);
        }
      }
    }

    // Sort the array based on the number of matches each word has.
    // We would want the strings with highest number of matches first
    // since that would allow us to eliminate the greatest number of
    // options in case of wrong guesses.
    Arrays.sort(wordlist, (word1, word2) -> matchCount.get(word2) - matchCount.get(word1));

    // Iterate through the array and keep removing options that
    // are sure to not be the secret word.
    for (int i = 0; i < wordlist.length; ++i) {
      String word = wordlist[i];

      // check if this word was eliminated.
      if (word.length() == 0)
        continue;

      // find the number of matches with secret word.
      int matches = master.guess(word);

      // if we have 6 matches then this is the secret word.
      if (matches == 6)
        break;

      // prune all options which don't have exactly 'matches' number of matches
      // with the current words.
      // Because all words with more than 'matches' matches will definitely not be
      // the secret word (since they are matching with some letters of current word
      // that
      // are not in secret word).
      prune(word, i + 1, matches, wordlist);
    }
  }

  private void prune(String word, int startIndex, int matches, String[] wordlist) {
    for (int i = startIndex; i < wordlist.length; ++i) {
      String currWord = wordlist[i];

      // skip check if this word was already pruned.
      if (currWord.length() == 0)
        continue;

      // if current word being checked doesn't match 'word' exactly 'match' times
      // prune it.
      if (compareStrings(word, currWord) != matches)
        wordlist[i] = "";
    }
  }

  private int compareStrings(String word1, String word2) {
    int count = 0;
    for (int i = 0; i < word1.length(); ++i) {
      if (word1.charAt(i) == word2.charAt(i))
        count++;
    }
    return count;
  }
}