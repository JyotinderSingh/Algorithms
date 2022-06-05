// https://leetcode.com/problems/course-schedule/

import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;

class Solution {
  HashMap<Integer, List<Integer>> courseDict;
  /*
   * finished[i] can take one of three values:
   * -1 -> the node i has never been visited
   * 0 -> the node i has been visited but is currently in process of completing
   * pre-requisites
   * 1 -> the node i has finished both the pre-requisites and the course
   */
  int[] finished;

  public boolean canFinish(int numCourses, int[][] prerequisites) {
    // course -> list of next courses.
    courseDict = new HashMap<>();

    // build the graph.
    for (int[] dependency : prerequisites) {
      // dependency[0] depends on dependency[1].
      courseDict.putIfAbsent(dependency[1], new LinkedList<>());
      courseDict.get(dependency[1]).add(dependency[0]);
    }

    finished = new int[numCourses];
    // Initially none of the nodes have been visited.
    for (int i = 0; i < numCourses; ++i) {
      finished[i] = -1;
    }

    for (int course = 0; course < numCourses; ++course) {
      if (isCycle(course)) {
        return false;
      }
    }
    return true;
  }

  boolean isCycle(int currCourse) {
    // If this node has already been visited and has completed all
    // its pre-requisites.
    if (finished[currCourse] == 1) {
      return false;
    }

    // If this node has been visited, but is still looking to
    // complete all its pre-requisites.
    // (basically a cycle).
    if (finished[currCourse] == 0) {
      return true;
    }

    // mark this node as visited and in progress.
    finished[currCourse] = 0;

    // postorder DFS, to visit all its children first.
    for (Integer child : courseDict.getOrDefault(currCourse, new LinkedList<>())) {
      if (isCycle(child)) {
        return true;
      }
    }

    // After visiting all the children, we come back to process the node
    // itself. Mark this course as completed.
    finished[currCourse] = 1;

    return false;
  }
}