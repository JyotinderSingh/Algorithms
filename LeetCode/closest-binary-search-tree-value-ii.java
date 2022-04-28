// https://leetcode.com/problems/closest-binary-search-tree-value-ii/

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

// QuickSelect
// Time: O(n)
// Space: O(n)

class Solution {
  List<Integer> nums;
  double target;

  private void swap(int a, int b) {
    int temp = nums.get(a);
    nums.set(a, nums.get(b));
    nums.set(b, temp);
  }

  private void quickSelect(int left, int right, int kSmallest) {
    // base case: the list contains only 1 element
    if (left >= right)
      return;

    // Pick a random pivot in bounds [left, right].
    int chosenPivotIndex = ThreadLocalRandom.current().nextInt(left, right + 1);

    /*
     * Execute the actual partitioning and get back the final position
     * of the pivot we chose after the partitioning is over
     */
    int finalIndexOfChosenPivot = partition(left, right, chosenPivotIndex);

    if (kSmallest == finalIndexOfChosenPivot) {
      return;
    } else if (kSmallest < finalIndexOfChosenPivot) {
      quickSelect(left, finalIndexOfChosenPivot - 1, kSmallest);
    } else {
      quickSelect(finalIndexOfChosenPivot + 1, right, kSmallest);
    }
  }

  private int partition(int left, int right, int pivotIndex) {
    double pivotDist = dist(pivotIndex);

    int lesserItemsTailIndex = left;

    // 1. Move the pivot to the end and out of the way.
    swap(pivotIndex, right);

    // 2. Partition
    for (int i = left; i < right; ++i) {
      if (dist(i) < pivotDist) {
        swap(i, lesserItemsTailIndex);
        lesserItemsTailIndex++;
      }
    }

    // 3. Move the pivot to it's final position.
    swap(lesserItemsTailIndex, right);

    return lesserItemsTailIndex;
  }

  private double dist(int i) {
    return Math.abs(nums.get(i) - target);
  }

  private void inorder(TreeNode node, List<Integer> nums) {
    if (node == null)
      return;
    inorder(node.left, nums);
    nums.add(node.val);
    inorder(node.right, nums);
  }

  public List<Integer> closestKValues(TreeNode root, double target, int k) {
    this.nums = new ArrayList<>();
    this.target = target;

    inorder(root, nums);

    quickSelect(0, nums.size() - 1, k);

    return nums.subList(0, k);
  }
}

// Heap
// Time: O(nlogk)
// Space: O(k)

class Solution {

  private void inorder(TreeNode node, PriorityQueue<Integer> heap, int k) {
    if (node == null)
      return;
    inorder(node.left, heap, k);

    heap.add(node.val);
    if (heap.size() > k) {
      heap.remove();
    }

    inorder(node.right, heap, k);
  }

  public List<Integer> closestKValues(TreeNode root, double target, int k) {
    // We add minus in front of the comparator since we want the the top of
    // the heap to be the element that is the 'least closest' or in other words
    // the farthest - since we would want to keep removing that.
    PriorityQueue<Integer> heap = new PriorityQueue<>(Comparator.comparingDouble(n -> -Math.abs(n - target)));

    inorder(root, heap, k);

    return new ArrayList<>(heap);
  }
}

// Recursive Inorder + Sort
// Time: O(nlog(n)), Space: O(n)

class Solution {

  private void inorder(TreeNode node, List<Integer> nums) {
    if (node == null)
      return;
    inorder(node.left, nums);
    nums.add(node.val);
    inorder(node.right, nums);
  }

  public List<Integer> closestKValues(TreeNode root, double target, int k) {
    List<Integer> nums = new ArrayList<>();
    inorder(root, nums);

    nums.sort(Comparator.comparingDouble(a -> Math.abs(a - target)));

    // now the list is sorted in order of closeness to target.
    return nums.subList(0, k);
  }
}
