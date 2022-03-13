import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

// https://leetcode.com/problems/decode-string/

class Solution {
  public String decodeString(String s) {
    Stack<Character> stack = new Stack<>();

    // Traverse the string
    for (int i = 0; i < s.length(); ++i) {
      /**
       * Build the stack:
       * - keep adding characters to the stack, until you hit ']'.
       * This is when you need to start decoding the innermost
       * encoded string (yet).
       **/

      // Case: we need to start decoding the string.
      if (s.charAt(i) == ']') {
        List<Character> decodedString = new ArrayList<>();
        // get the encoded string
        while (stack.peek() != '[') {
          // We build the array containing the chars of decoded string (reverse order).
          decodedString.add(stack.pop());
        }

        // pop the '[' from the stack
        stack.pop();

        // We are now scanning the number
        int base = 1;
        int k = 0;
        while (!stack.isEmpty() && Character.isDigit(stack.peek())) {
          k += (stack.pop() - '0') * base;
          base *= 10;
        }

        // decode k[decodedString], by pushing k times into the stack.
        while (k != 0) {
          // Push the numbers back into the stack starting from last
          // index of array, so chars are in same relative order as before.
          for (int j = decodedString.size() - 1; j >= 0; j--) {
            stack.push(decodedString.get(j));
          }
          k--;
        }
      } else {
        stack.push(s.charAt(i));
      }
    }

    char[] result = new char[stack.size()];
    // we hydrate the result from behind since we fetch the numbers in reverse from
    // stack.
    for (int i = result.length - 1; i >= 0; i--) {
      result[i] = stack.pop();
    }

    return new String(result);
  }
}