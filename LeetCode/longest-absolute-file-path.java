// https://leetcode.com/problems/longest-absolute-file-path/

import java.util.ArrayDeque;
import java.util.Deque;

class Solution {
  public int lengthLongestPath(String input) {
    // Stores the max length of path upto a certain level.
    Deque<Integer> stack = new ArrayDeque<>();

    // Dummy element to make calculating the length
    // of root easier.
    stack.push(0);
    int maxLen = 0;

    // We iterate through each subpath component and check it's length.
    // We also keep track of the max length found so far.
    for (String subPath : input.split("\n")) {
      int level = subPath.lastIndexOf("\t") + 1;
      // calculate path length till current element.
      int subPathLength = subPath.length() - level; // removing '\t' chars.

      // Pop till you reach the parent element of current subPath in the stack.
      // We are basically removing all deeper entries from the stack.
      // We do (+ 1) due to the dummy element in stack.
      while (level + 1 < stack.size())
        stack.pop();

      // we are now at parent element
      // the top element of stack is the length of
      // path till the parent element (inclusive)
      // Check if the current subPath component is a filename
      if (subPath.contains(".")) {
        maxLen = Math.max(maxLen, stack.peek() + subPathLength);
      } else {
        // Add this path component to the stack
        // We add + 1 to account for adding an '/' to the path.
        stack.push(stack.peek() + subPathLength + 1);
      }
    }
    return maxLen;
  }
}
