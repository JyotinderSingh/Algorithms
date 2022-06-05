// https://leetcode.com/problems/course-schedule-ii/

class Solution {
  /*
   * finished[i] can take one of three values:
   * -1 -> the node i has never been visited
   * 0 -> the node i has been visited but is currently in process of completing
   * pre-requisites
   * 1 -> the node i has finished both the pre-requisites and the course
   */
  int[] finished;
  List<Integer> result;
  // course -> [all pre-requisite courses].
  Map<Integer, List<Integer>> adj;

  public int[] findOrder(int numCourses, int[][] prerequisites) {
    result = new ArrayList<>(numCourses);
    // initialize the finished array and mark all nodes as
    // unvisited.
    finished = new int[numCourses];
    for (int i = 0; i < numCourses; ++i) {
      finished[i] = -1;
    }

    // initialize the graph.
    adj = new HashMap<>();
    for (int[] pre : prerequisites) {
      adj.putIfAbsent(pre[0], new LinkedList<>());
      adj.get(pre[0]).add(pre[1]);
    }

    // start topological ordering of graph using dfs.
    for (int course = 0; course < numCourses; ++course) {
      if (!getTopologicalOrderDfs(course)) {
        return new int[] {};
      }
    }

    return result.stream().mapToInt(i -> i).toArray();
  }

  boolean getTopologicalOrderDfs(int course) {
    // This node has already been visited and has
    // completed all its pre-reqs. This also means
    // its pre-reqs have been added to the result list as well.
    if (finished[course] == 1)
      return true;
    // This node has been visited but is still looking to complete
    // its pre-reqs. This means this is a cycle.
    if (finished[course] == 0)
      return false;

    // mark this course as visited and in progress.
    finished[course] = 0;

    // post-order DFS, we process the course's pre-reqs before the course itself.
    for (int child : adj.getOrDefault(course, new LinkedList<>())) {
      if (!getTopologicalOrderDfs(child)) {
        return false;
      }
    }

    // mark this course as completed.
    finished[course] = 1;

    // now that all the dependencies of this course have been satisfied
    // (All pre-reqs were added during the DFS already) we can
    // finally add this course to the result list.
    result.add(course);

    return true;
  }
}