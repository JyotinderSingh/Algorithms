// https://leetcode.com/problems/trapping-rain-water/submissions/
// https://www.youtube.com/watch?v=XqTBrQYYUcc


// Two Pointer (92%, 14%)
class Solution {
  public int trap(int[] height) {
    int leftMax = 0, rightMax = 0;
    int left = 0, right = height.length - 1;
    int result = 0;

    while (left < right) {
      if (leftMax < height[left]) {
        leftMax = height[left];
      }
      if (rightMax < height[right]) {
        rightMax = height[right];
      }

      if (leftMax < rightMax) {
        result += leftMax - height[left];
        left++;
      } else {
        result += rightMax - height[right];
        right--;
      }
    }
    return result;
  }
}

// Maintain 2 vectors (51%, 28%)

class Solution {
  public int trap(int[] height) {
    int[] maxOnLeft = new int[height.length];
    int[] maxOnRight = new int[height.length];

    maxOnLeft[0] = height[0];
    for (int i = 1; i < height.length; ++i) {
      maxOnLeft[i] = Math.max(maxOnLeft[i - 1], height[i]);
    }

    maxOnRight[height.length - 1] = height[height.length - 1];
    for (int i = height.length - 2; i >= 0; --i) {
      maxOnRight[i] = Math.max(maxOnRight[i + 1], height[i]);
    }

    int result = 0;
    for (int i = 0; i < height.length; ++i) {
      result += Math.min(maxOnLeft[i], maxOnRight[i]) - height[i];
    }

    return result;
  }
}