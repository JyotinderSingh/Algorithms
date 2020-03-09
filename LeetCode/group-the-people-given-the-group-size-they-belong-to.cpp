// https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/submissions/

class Solution
{
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes)
    {

        map<int, vector<int>> groupSet;

        vector<vector<int>> result;

        for (int i = 0; i < groupSizes.size(); ++i)
        {
            int size = groupSizes[i];

            groupSet[size].push_back(i);

            if (groupSet[size].size() == size)
            {
                result.push_back(groupSet[size]);
                groupSet[size].clear();
            }
        }

        return result;
    }
};