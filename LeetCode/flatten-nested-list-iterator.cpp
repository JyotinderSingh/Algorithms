// https://leetcode.com/problems/flatten-nested-list-iterator/
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator
{
    vector<int> res;
    int iter = 0;

public:
    void recurse(vector<NestedInteger> &nestedList)
    {
        for (int i = 0; i < nestedList.size(); ++i)
        {
            if (nestedList[i].isInteger())
            {
                res.push_back(nestedList[i].getInteger());
            }
            else
            {
                recurse(nestedList[i].getList());
            }
        }
    }

    NestedIterator(vector<NestedInteger> &nestedList)
    {
        recurse(nestedList);
    }

    int next()
    {
        if (hasNext())
        {
            return res[iter++];
        }
        return -1;
    }

    bool hasNext()
    {
        if (iter == res.size())
        {
            return false;
        }
        return true;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */