// https://leetcode.com/problems/meeting-rooms/

class Solution {
  public boolean canAttendMeetings(int[][] intervals) {
    Arrays.sort(intervals, (a, b) -> {
      if (a[0] != b[0]) {
        return a[0] - b[0];
      } else {
        return a[1] - b[1];
      }
    });

    for (int i = 0; i < intervals.length - 1; ++i) {
      if (intervals[i][1] > intervals[i + 1][0]) {
        return false;
      }
    }
    return true;
  }
}