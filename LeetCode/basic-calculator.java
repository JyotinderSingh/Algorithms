// https://leetcode.com/problems/basic-calculator/
// https://leetcode.com/problems/basic-calculator/discuss/62361/Iterative-Java-solution-with-stack
// https://leetcode.com/problems/basic-calculator/discuss/62361/Iterative-Java-solution-with-stack/64037

import java.util.Stack;

class Solution {
  public int calculate(String s) {
    Stack<Integer> stack = new Stack<>();
    int result = 0;
    int num = 0;
    int lastSign = 1;

    for (char ch : s.toCharArray()) {
      // We are building the number.
      if (Character.isDigit(ch)) {
        num = (num * 10) + (ch - '0');
      } else if (ch == '+') {
        // flush the number we just built to the result.
        // We multiply it by the corresponding sign that was present before this number.
        result += lastSign * num;

        num = 0; // reset the number.
        lastSign = 1;
      } else if (ch == '-') {
        // flush the number we just build to the result.
        // We multiply it by the corresponding sign that was present before this number.
        result += lastSign * num;

        num = 0; // reset the number
        lastSign = -1;
      } else if (ch == '(') {
        // We entering a paranthesis.
        // We first save the result accumulated so far to the stack.
        stack.push(result);
        // We also want to push in the sign just before this paranthesis
        // to the stack, since it will influence the sign of all the elements
        // inside this paranthesis.
        stack.push(lastSign);

        // reset the sign and result for the paranthesis evaluation.
        lastSign = 1;
        result = 0;
      } else if (ch == ')') {
        // We are now exiting the paranthesis.
        // Now we need to merge the result we just calculated for the expression
        // inside said paranthesis with the one we had stored on the stack (from the
        // outside experession).
        // First we flush the number we have on our hand to the paranthesis result.
        result += lastSign * num;
        num = 0; // reset the number.

        // Now we want to set the sign of this entire result, based on the sign
        // that was present in front of the paranthesis (we had pushed this to the
        // stack).
        result *= stack.pop();

        // Finally add this result to the external result we had accumulated before
        // entering the
        // paranthesis.
        result += stack.pop();
      }
    }

    if (num != 0)
      result += lastSign * num;

    return result;
  }
}

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