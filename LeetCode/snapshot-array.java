// https://leetcode.com/problems/snapshot-array/

/**
 * Intuition
 *
 * Instead of copying the whole array,
 * we can only record the changes in the set.
 *
 *
 * Explanation
 *
 * The idea is, the whole array can be large,
 * and we may take the snap tons of times.
 * (Like you may always ctrl + S twice)
 *
 * Instead of recording the history of the whole array,
 * we will only record the history of each cell.
 * And this is the minimum space that we need to record all information.
 *
 * For each A[i], we will record its history.
 * With a snap_id and a its value.
 *
 * When we want to get the value in history, just binary search the time point.
 * for example, we want to get the value of A[i] at time point t.
 * We can use binary search to find the time point t. If there is no specific
 * entry of that time point, we will return the value of the previous time point
 * that was stored - since it means the value had not changed after that 
 * previous time point.
 *
 *
 * Complexity
 *
 * Time O(logS)
 * Space O(S)
 * where S is the number of set called.
 *
 * SnapshotArray(int length) is O(N) time
 * set(int index, int val) is O(1) in Python and O(logSnap) in Java
 * snap() is O(1)
 * get(int index, int snap_id) is O(logSnap)
 */
import java.util.TreeMap;

class SnapshotArray {
  // Array of TreeMaps. Each number in the array
  // Will be stored as an entry in the TreeMap where
  // Key is the snap_id, and value is the value stored in the arary
  // at that snap_id. (These entries will be in sorted order based on key).
  TreeMap<Integer, Integer>[] arr;
  int snap_id = 0;

  public SnapshotArray(int length) {
    arr = new TreeMap[length];
    for (int i = 0; i < length; ++i) {
      arr[i] = new TreeMap<Integer, Integer>();
      // Initially all elements are set to 0.
      // Key = 0, as initial snap_id is 0.
      arr[i].put(0, 0);
    }
  }

  public void set(int index, int val) {
    // Update the history of arr[index] with new value at the current snap_id.
    arr[index].put(snap_id, val);
  }

  public int snap() {
    return snap_id++;
  }

  public int get(int index, int snap_id) {
    // floor_entry because we want to find value at snap_id equal to or smaller
    // than the provided snap_id.
    return arr[index].floorEntry(snap_id).getValue();
  }
}

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray obj = new SnapshotArray(length);
 * obj.set(index,val);
 * int param_2 = obj.snap();
 * int param_3 = obj.get(index,snap_id);
 */