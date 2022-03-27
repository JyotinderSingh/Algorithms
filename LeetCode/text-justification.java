// https://leetcode.com/problems/text-justification/

class Solution {
  public List<String> fullJustify(String[] words, int maxWidth) {
    List<String> result = new ArrayList<>();

    int start = 0, end = 0;
    while (start < words.length) {
      // First find out how many words we can fit in this line.
      end = findLastWordIndex(words, start, maxWidth);
      // Now that we know how many words we have in the line,
      // we can distribute the space among them.
      String line = justify(words, start, end, maxWidth);
      // Add the line to the result list.
      result.add(line);
      // update the start pointer
      start = end + 1;
    }

    return result;
  }

  /**
   * Returns the index of the last word that will be able to fit in this line.
   * 
   * @param words    the array of words
   * @param start    the index of the first word of the line
   * @param maxWidth the maximum width of the line
   * @return the index of the last word that will be able to fit in this line.
   */
  private int findLastWordIndex(String[] words, int start, int maxWidth) {
    int i = start;

    // Take the word at the index i from the list
    int currWidth = words[i].length();
    i++;

    while (i < words.length && (currWidth + 1 + words[i].length() <= maxWidth)) {
      // We add the length of the word at
      currWidth += 1 + words[i].length();
      i++;
    }

    // end now points at the next index so -1
    return i - 1;
  }

  /**
   * Justifies a single line of words.
   * 
   * @param words    the array of words
   * @param start    the index of the first word of the line
   * @param end      the index of the last word of the line
   * @param maxWidth the maximum width of the line
   * @return the justified line
   */
  private String justify(String[] words, int start, int end, int maxWidth) {
    // If there is only one word, we just add extra spaces to its right
    if (end - start == 0)
      return padResult(words[start], maxWidth);

    // If this is the last line, end will be pointing to the last element.
    boolean isLastLine = end == words.length - 1;

    int lengthOfWords = 0;
    for (int i = start; i <= end; ++i) {
      lengthOfWords += words[i].length();
    }

    int numSpaces = maxWidth - lengthOfWords;
    // for total of 3 words, j=2, i=0 so 2 words to pad (since we don't pad last
    // one)
    int numWordsToPad = end - start;

    StringBuilder sb = new StringBuilder();

    // SpaceStr is the string with the right number of spaces that should be
    // attached to each word (numWordsToPad)
    // In last line we just do single space separation (given in problem statement).
    String spaceStr = isLastLine ? " " : blank(numSpaces / numWordsToPad);
    // remainderSpaceCount is the number of extra spaces that need to be attached to
    // first words (from left).
    int remainderSpaceCount = isLastLine ? 0 : numSpaces % numWordsToPad;

    for (int i = start; i <= end; ++i) {
      // Add the word and the spaceStr to the stringBuilder.
      // Notice how the spaceStr will end up getting attached to the last word also -
      // we'll need to trim it later.
      sb.append(words[i]).append(spaceStr);

      // Add any remaining extra spaces
      if (remainderSpaceCount > 0) {
        sb.append(" ");
        remainderSpaceCount--;
      }
    }

    // Trim the extra spaces that were added to the last word in the loop.
    String line = sb.toString().trim();

    // if the last word still needs to be padded.
    return padResult(line, maxWidth);
  }

  /**
   * Pads the result to the maxWidth.
   * 
   * @param str      the string to pad
   * @param maxWidth the maximum width of the line
   * @return the padded string
   */
  private String padResult(String str, int maxWidth) {
    return str + blank(maxWidth - str.length());
  }

  /**
   * Returns a string with the given number of spaces.
   * 
   * @param count the number of spaces
   * @return the string with the given number of spaces
   */
  private String blank(int count) {
    StringBuilder sb = new StringBuilder();
    while (count-- != 0) {
      sb.append(" ");
    }
    return sb.toString();
  }
}
