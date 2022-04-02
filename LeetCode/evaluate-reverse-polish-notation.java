// https://leetcode.com/problems/evaluate-reverse-polish-notation/

import java.util.HashMap;
import java.util.Map;
import java.util.Stack;
import java.util.function.BiFunction;


// Lambda code:

class Solution {
  private static final Map<String, BiFunction<Integer, Integer, Integer>> OPERATIONS = new HashMap<>();

  // Ensure that this only gets done once for ALL test cases.
  static {
    OPERATIONS.put("+", (a, b) -> a + b);
    OPERATIONS.put("-", (a, b) -> a - b);
    OPERATIONS.put("*", (a, b) -> a * b);
    OPERATIONS.put("/", (a, b) -> a / b);
  }

  public int evalRPN(String[] tokens) {
    Stack<Integer> stack = new Stack<>();

    for (String token : tokens) {
      if (!OPERATIONS.containsKey(token)) {
        stack.push(Integer.valueOf(token));
        continue;
      }

      int number2 = stack.pop();
      int number1 = stack.pop();

      BiFunction<Integer, Integer, Integer> operation = OPERATIONS.get(token);
      int result = operation.apply(number1, number2);
      stack.push(result);
    }
    return stack.pop();
  }
}

// Without lambda code:

class Solution {
  public int evalRPN(String[] tokens) {
    Stack<Integer> stack = new Stack<>();

    for (String token : tokens) {
      if (!"+-*/".contains(token)) {
        stack.push(Integer.valueOf(token));
        continue;
      }

      int n2 = stack.pop();
      int n1 = stack.pop();

      int result = 0;

      switch (token) {
        case "+":
          result = n1 + n2;
          break;
        case "-":
          result = n1 - n2;
          break;
        case "*":
          result = n1 * n2;
          break;
        case "/":
          result = n1 / n2;
          break;
      }

      stack.push(result);
    }
    return stack.pop();
  }
}