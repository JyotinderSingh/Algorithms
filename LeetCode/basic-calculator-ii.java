// https://leetcode.com/problems/basic-calculator-ii/

// No stack solution
// Time: O(n), Space: O(1)
// Better to understand stack approach first.

class Solution {
  public int calculate(String s) {
    int result = 0;
    int lastNum = 0;
    int currNum = 0;
    char lastOperand = '+';

    for (int i = 0; i < s.length(); ++i) {
      char ch = s.charAt(i);

      if (Character.isDigit(ch)) {
        currNum = (currNum * 10) + (ch - '0');
      }

      // We enter this condition if either this is the last character
      // being scanned (in this case we would want to flush this number to the
      // result).
      // or
      // this character is an operator.
      if (i == s.length() - 1 || !Character.isDigit(ch) && ch != ' ') {
        switch (lastOperand) {
          case '+':
            result += lastNum;
            lastNum = currNum;
            break;
          case '-':
            result += lastNum;
            lastNum = -currNum;
            break;
          case '*':
            lastNum *= currNum;
            break;
          case '/':
            lastNum /= currNum;
            break;
        }
        lastOperand = ch;
        currNum = 0;
      }
    }

    // Add the last accumulated number to the result.
    result += lastNum;
    return result;
  }
}

// Stack solution
// Time: O(n), Space: O(n)

class Solution {
  public int calculate(String s) {
    if (s == null || s.length() == 0)
      return 0;

    // we add an extra '+' operator at the end of the string so that
    // we flush the last number formed in the loop below to the stack.
    // otherwise we exit the loop and never really push it into the stack.
    // We could do it separately outside the loop as well, but then we would
    // have to take care of the case if the operator before this number was '-'.
    // It's easier to handle this way since every case is taken care of inside the
    // loop.
    s += "+";

    Stack<Integer> stack = new Stack<>();
    char lastOperand = '+';
    int num = 0;

    // we iterate through the characters and keep track of the last sign we saw.
    // We keep solving '*' and '/' operations on the fly, and keep accumulating
    // addition operations in the stack for later evaluation.
    for (char ch : s.toCharArray()) {
      // Are we building am operand?
      if (Character.isDigit(ch)) {
        num = (num * 10) + (ch - '0');
        continue;
      }

      if (ch == ' ')
        continue;

      // We are here because we have finished parsing the number
      // Now we can simply push the result to the stack depending on
      // whatever operator was in front of the number we just parsed.
      if (lastOperand == '+') {
        stack.push(num);
      } else if (lastOperand == '-') {
        // we can convert '-' into addition by turning the operand negative.
        stack.push(-num);
      } else if (lastOperand == '/') {
        stack.push(stack.pop() / num);
      } else if (lastOperand == '*') {
        stack.push(stack.pop() * num);
      }

      // since this was an operator, update 'op'
      lastOperand = ch;
      // reset operand to 0.
      num = 0;
    }

    // We now have all the easily evaluable numbers in the stack,
    // we can just iterate through them and keep adding them to our result.
    int result = 0;
    while (!stack.isEmpty()) {
      result += stack.pop();
    }

    return result;
  }
}