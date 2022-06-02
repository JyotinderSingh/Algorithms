// https://leetcode.com/problems/meeting-rooms-ii/

class Solution {
  public int minMeetingRooms(int[][] intervals) {
    if (intervals.length == 0) {
      return 0;
    }

    // Min Heap - will hold intervals sorted by end time.
    // Top element will be the interval that ends first.
    // We just store the end time (since we don't really require the start time in
    // this).
    PriorityQueue<Integer> allocator = new PriorityQueue<>(intervals.length,
        Comparator.comparingInt(a -> a));

    // Sort the intervals by start time.
    Arrays.sort(intervals, Comparator.comparingInt(a -> a[0]));

    // Add the first meeting.
    allocator.add(intervals[0][1]);

    // Iterate over the remaining intervals.
    for (int i = 1; i < intervals.length; ++i) {
      // If the room due to free up the earliest is free, assign that room to this
      // meeting.
      if (intervals[i][0] >= allocator.peek()) {
        allocator.poll();
      }

      // If a new room is to be assigned, then we add it to the heap.
      // If an old room is allocated, then by now we have removed the older meeting
      // from their
      // in the 'if' condition above, so now also we have to add the current meeting
      // to the heap
      // with the updated end time.
      allocator.add(intervals[i][1]);
    }

    return allocator.size();
  }
}