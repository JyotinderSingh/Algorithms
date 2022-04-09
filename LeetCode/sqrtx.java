// https://leetcode.com/problems/sqrtx/

class Solution {
  public int mySqrt(int x) {
    if (x < 2)
      return x;

    long num;
    int left = 2, right = x / 2;
    while (left <= right) {
      int pivot = left + (right - left) / 2;
      num = (long) pivot * pivot;
      if (num < x)
        left = pivot + 1;
      else if (num > x)
        right = pivot - 1;
      else
        return pivot;
    }
    return right;
  }
}