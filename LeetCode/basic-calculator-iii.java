// https://leetcode.com/problems/basic-calculator-iii/
// https://leetcode.com/problems/basic-calculator-iii/discuss/152092/O(n)-Java-Recursive-Simple-Solution

import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Stack;

class Solution {
  public int calculate(String s) {
    if (s == null)
      return 0;

    // Queue makes it easier to go through the string and
    // discard processed characters (helpful in recursive calls
    // since we don't need to worry about already processed chars)
    Queue<Character> q = new ArrayDeque<>();
    for (char ch : s.toCharArray()) {
      q.offer(ch);
    }

    // Add a dummy end char to allow last number we build to be flushed
    // to the result.
    q.offer('+');

    return cal(q);
  }

  /**
   * Processes each 'piece' of the expression separately in its own recursive
   * call. We process each pair of paranthesis in it's own stack.
   */
  private int cal(Queue<Character> q) {
    // holds the last operator we parsed.
    char prevOperator = '+';
    int num = 0;
    Stack<Integer> stack = new Stack<>();

    while (!q.isEmpty()) {
      char ch = q.poll();

      if (ch == ' ')
        continue;

      // We are building a number.
      if (Character.isDigit(ch)) {
        num = (num * 10) + (ch - '0');
      } else if (ch == '(') {
        // Process the expression inside this pair of paranthesis
        // in it's own recursive call and get the result.
        num = cal(q);
      } else {
        // process the last operator we encountered.
        switch (prevOperator) {
          case '+':
            stack.push(num);
            break;
          case '-':
            stack.push(-num);
            break;
          case '*':
            stack.push(stack.pop() * num);
            break;
          case '/':
            stack.push(stack.pop() / num);
            break;
        }

        if (ch == ')') {
          // Encountering this character means we were inside a recursive
          // call and were processing an expression inside a pair of paranthesis.
          // just break out and calculate the accumulated result until now and return.
          break;
        }

        // update the operator based on whatever the current char is.
        prevOperator = ch;
        // reset the num
        num = 0;
      }
    }

    int result = 0;
    while (!stack.isEmpty())
      result += stack.pop();
    return result;
  }
}