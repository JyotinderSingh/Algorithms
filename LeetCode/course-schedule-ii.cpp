// https://leetcode.com/problems/course-schedule-ii/
class Solution
{
    /*
    * finished[i] can take one of three values:
    * -1 -> the node i has never been visited
    * 0  -> the node i has been visited but is currently in process of completing pre-requisites
    * 1  -> the node i has finished both the pre-requisites and the course
    */
    vector<int> res;
    vector<int> finished;
    vector<vector<int>> adj;

public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {

        // initialize the finished array and mark every node unvisited
        finished = vector<int>(numCourses, -1);

        // initialize the graph and populate it
        adj = vector<vector<int>>(numCourses);
        for (auto pre : prerequisites)
        {
            adj[pre[0]].push_back(pre[1]);
        }

        // begin dfs topological sort on the graph
        for (int i = 0; i < numCourses; ++i)
        {
            if (!dfs(i))
            {
                vector<int> temp;
                return temp;
            }
        }
        return res;
    }

    bool dfs(int start)
    {
        // if this node has has already been visited and has completed all it pre-requisites
        if (finished[start] == 1)
        {
            return true;
        }

        // if this node has been visited, but is still looking to complete its prerequisites
        // (basically a cycle)
        if (finished[start] == 0)
        {
            return false;
        }

        // mark this node as visited and in progress
        finished[start] = 0;

        // scan all the prereq node (children) of the current node
        for (auto child : adj[start])
        {
            if (!dfs(child))
            {
                return false;
            }
        }

        // mark the course (node) as completed
        finished[start] = 1;

        // now that all the dependencies of this node have been satisfied
        // add this to the result
        res.push_back(start);

        return true;
    }
};