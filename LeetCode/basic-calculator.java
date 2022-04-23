// https://leetcode.com/problems/basic-calculator/

import java.util.Stack;

class Solution {
  public int calculate(String s) {
    int operand = 0;
    int factor = 1;
    Stack<Object> stack = new Stack<>();

    // We need to understand how + and - work. '+' follows the associative property.
    // For the expression A+B+C, we have (A+B)+C = A+(B+C).
    // However, '-' does not follow this rule which is the root cause of all the
    // problems in this approach.
    // If we use a stack and read the elements of the expression from left to right,
    // we end up evaluating the expression from right-to-left.
    // This means we are expecting (A-B)-C to be equal to (C-B)-A = (C−B)−A which
    // is not correct. Subtraction is neither associative nor commutative.
    // This problem could be solved very easily by reversing the string.
    // Reversing a string helps since we now put the elements of the expression into
    // the stack from right to left and evaluation for the expression is done
    // correctly from left to right.
    for (int i = s.length() - 1; i >= 0; --i) {
      char ch = s.charAt(i);

      // Build the operand.
      if (Character.isDigit(ch)) {
        // We are building the number in reverse order.
        operand = (factor * (ch - '0')) + operand;
        factor *= 10;
      } else if (ch != ' ') {
        // Were we building a number?
        if (factor != 1) {
          // Save the operand built so far to the stack, since
          // now we have encountered a non-digit.
          stack.push(operand);
          // reset factor and operand.
          factor = 1;
          operand = 0;
        }

        // Check if we are end of paranthesis - if yes then evaluate
        // the expression inside the paranthesis.
        // We had reversed the string. So end of paranthesis is now
        // denoted by an opening bracket.
        if (ch == '(') {
          int res = evaluateExpr(stack);
          // pop the remaining ')' character from the stack.
          stack.pop();

          // Append the evaluated result to the stack.
          // This result could be of a sub expression
          stack.push(res);
        } else {
          // For other non digits just push onto the stack.
          stack.push(ch);
        }
      }
    }

    // Push the last operand to the stack if any.
    if (factor != 1) {
      stack.push(operand);
    }

    // Evaluate any left overs in the stack
    return evaluateExpr(stack);
  }

  private int evaluateExpr(Stack<Object> stack) {
    // If the stack is empty or the expression starts with a symbol,
    // then append 0 to the stack.
    // i.e. [1, '-', 2, '-'] becomes [1, '-', 2, '-', 0]
    if (stack.isEmpty() || !(stack.peek() instanceof Integer)) {
      stack.push(0);
    }

    // Get the first operand.
    int res = (int) stack.pop();

    // Evaluate the expression till we get the corresponding ')'.
    while (!stack.empty() && !((char) stack.peek() == ')')) {
      char sign = (char) stack.pop();

      if (sign == '+') {
        res += (int) stack.pop();
      } else {
        res -= (int) stack.pop();
      }
    }
    return res;
  }
}