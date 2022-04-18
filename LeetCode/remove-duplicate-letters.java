// https://leetcode.com/problems/remove-duplicate-letters/

// Stack
// Time: O(n), Space: O(1)

class Solution {
  public String removeDuplicateLetters(String s) {
    Stack<Character> stack = new Stack<>();

    // this lets us keep track of what's in our solution in O(1) time.
    int[] seen = new int[26];

    // this will let us know if there are any more instances of s[i] left in s
    // by storing the last index of the s[i]'s occurrence.
    int[] last_occurrence = new int[26];
    for (int i = 0; i < s.length(); ++i)
      last_occurrence[s.charAt(i) - 'a'] = i;

    for (int i = 0; i < s.length(); ++i) {
      char c = s.charAt(i);

      // we can only add c if it is not already present in our solution,
      // this is to maintain only 1 of each character.
      if (seen[c - 'a'] == 0) {
        // if the last letter in our solution:
        // 1. exists
        // 2. is greater that c, so removing it will make the string lexicographically
        // smaller.
        // 3. is not the last of its kind in the remaining string.
        // we remove it from the stack to keep the solution optimal.
        while (!stack.isEmpty() && c < stack.peek() && last_occurrence[stack.peek() - 'a'] > i) {
          seen[stack.pop() - 'a']--;
        }
        seen[c - 'a']++;
        stack.push(c);
      }
    }

    StringBuilder sb = new StringBuilder(stack.size());
    // Note: for each loop over stack prints in FIFO order.
    for (Character c : stack)
      sb.append(String.valueOf(c));
    return sb.toString();
  }
}

// Greedy
// Time: O(n), Space: O(n)

class Solution {
  public String removeDuplicateLetters(String s) {
    // find pos - the index of the leftmost letter in our solution.
    // we create a counter and end the iteration once the suffix doesn't have
    // each unique character.
    // pos will be the index of the smallest character we encounter before the
    // iteration ends.
    int[] cnt = new int[26];
    int pos = 0;
    for (int i = 0; i < s.length(); ++i)
      cnt[s.charAt(i) - 'a']++;

    // The leftmost letter in our solution will be the smallest letter such that the
    // suffix from that letter contains every other. This is because we know that
    // the
    // solution must have one copy of every letter, and we know that the solution
    // will
    // have the lexicographically smallest leftmost character possible.
    // If there are multiple smallest letters, then we pick the leftmost one simply
    // because it gives us more options. We can always eliminate more letters later
    // on,
    // so the optimal solution will always remain in our search space.
    for (int i = 0; i < s.length(); ++i) {
      // As we iterate over our string, if character i is greater than character i+1
      // and another occurrence of character i exists later in the string,
      // deleting character i will always lead to the optimal solution.
      // Characters that come later in the string i don't matter in this calculation
      // because i is in a more significant spot. Even if character i+1 isn't the best
      // yet, we can always replace it for a smaller character down the line if
      // possible.
      if (s.charAt(i) < s.charAt(pos))
        pos = i;
      // this was the last index where the suffix contained all the characters at
      // least once.
      if (--cnt[s.charAt(i) - 'a'] == 0)
        break;
    }

    // our answer is the leftmost letter plus the recursive call on the remainder of
    // the string
    // note that we have to get reid of further occurrences of s[pos] to ensure that
    // there are
    // no duplicates.
    return s.length() == 0 ? ""
        : s.charAt(pos) + removeDuplicateLetters(s.substring(pos + 1).replaceAll("" + s.charAt(pos), ""));
  }
}