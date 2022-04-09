// https://leetcode.com/problems/longest-string-chain/

class Solution {
  public int longestStrChain(String[] words) {
    // This map will keep track of the longest possible word sequence
    // starting at this key.
    // What we do is whenever we encounter a new word,
    // we will find all possible sequences with that word.
    // Then, we will store the length of the longest possible sequence
    // that ends with this word.
    Map<String, Integer> memo = new HashMap<>();
    // Used to check if a word is present in the list.
    Set<String> wordsPresent = new HashSet<>();
    Collections.addAll(wordsPresent, words);

    int ans = 0;
    for (String word : words) {
      ans = Math.max(ans, dfs(wordsPresent, memo, word));
    }
    return ans;
  }

  int dfs(Set<String> wordsPresent, Map<String, Integer> memo, String currentWord) {
    // If this word is previously encountered, just return the corresponding value
    // present
    // in the map.
    if (memo.containsKey(currentWord)) {
      return memo.get(currentWord);
    }

    // This stores the maximum length of a word sequence possible with the
    // 'currentWord'.
    int maxLength = 1;
    StringBuilder sb = new StringBuilder(currentWord);

    // creating all possible strings taking out one character at a time from the
    // 'currentWord'.
    for (int i = 0; i < sb.length(); ++i) {
      sb.deleteCharAt(i);
      String newWord = sb.toString();
      // If the new word formed is present in the list, we do a dfs search with this
      // new word.
      if (wordsPresent.contains(newWord)) {
        int currentLength = 1 + dfs(wordsPresent, memo, newWord);
        maxLength = Math.max(maxLength, currentLength);
      }
      // Add back the character we just removed for this iteration.
      sb.insert(i, currentWord.charAt(i));
    }
    // We exhausted all possibilites from this word, so we know what is the max
    // possible length
    // of sequence possible starting from it.
    memo.put(currentWord, maxLength);

    return maxLength;
  }
}