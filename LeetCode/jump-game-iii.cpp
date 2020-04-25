// https://leetcode.com/problems/jump-game-iii/
class Solution
{
public:
    bool util(vector<int> &arr, vector<int> &visited, int start)
    {
        if (start < 0 || start >= arr.size() || visited[start] == 1)
        {
            return false;
        }
        // objective achieved
        if (arr[start] == 0)
        {
            return true;
        }
        visited[start] = 1;
        return util(arr, visited, start + arr[start]) || util(arr, visited, start - arr[start]);
    }

    bool canReach(vector<int> &arr, int start)
    {
        vector<int> visited(arr.size(), 0);
        return util(arr, visited, start);
    }
};