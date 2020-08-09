// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/discuss/231113/C%2B%2B-hashmap-vs.-map

/////////////////////////////////////////////////////////////
//////////////////////// USING MAP //////////////////////////
/////////////////////////////////////////////////////////////

class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, map<int, set<int>>> m;
        vector<vector<int>> res;

        traverse(root, 0, 0, m);

        for (auto itx = m.begin(); itx != m.end(); ++itx)
        {
            res.push_back(vector<int>());
            for (auto ity = itx->second.begin(); ity != itx->second.end(); ++ity)
            {
                res.back().insert(end(res.back()), begin(ity->second), end(ity->second));
            }
        }
        return res;
    }

    void traverse(TreeNode *root, int x, int y, map<int, map<int, set<int>>> &m)
    {
        if (!root)
            return;
        m[x][y].insert(root->val);

        traverse(root->left, x - 1, y + 1, m);
        traverse(root->right, x + 1, y + 1, m);
    }
};

/////////////////////////////////////////////////////////////
//////////////////// USING UNORDERED MAP ////////////////////
/////////////////////////////////////////////////////////////

/////////////////////////////////////
////// ITERATOR BEST PRACTICE ///////
/////////////////////////////////////

unordered_map<int, unordered_map<int, set<int>>> m;
void traverse(TreeNode *r, int x, int y)
{
    if (r != nullptr)
    {
        m[x][y].insert(r->val);
        traverse(r->left, x - 1, y + 1);
        traverse(r->right, x + 1, y + 1);
    }
}
vector<vector<int>> verticalTraversal(TreeNode *r)
{
    vector<vector<int>> res;
    traverse(r, 0, 0);
    for (int x = -999; x < 1000; ++x)
    {
        auto it = m.find(x);
        if (it != end(m))
        {
            res.push_back(vector<int>());
            for (int y = 0; y < 1000; ++y)
            {
                auto ity = it->second.find(y);
                if (ity != end(it->second))
                {
                    res.back().insert(end(res.back()), begin(ity->second), end(ity->second));
                }
            }
        }
    }
    return res;
}

/////////////////////////////////////
////// ITERATOR-LESS SOLUTION ///////
/////////////////////////////////////

class Solution
{
    int left, right;

public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        // map[x_coord] --> map[y_coord] ---> set[elements at that position, in sorted order]
        unordered_map<int, unordered_map<int, set<int>>> m;

        // build the mapping
        traverse(root, 0, 0, m);

        vector<vector<int>> res;

        // traverse through all the possible x-coordinates
        for (int x = -999; x <= 999; ++x)
        {

            // if an element exists at the current x-coordinate
            if (m.find(x) != m.end())
            {
                res.push_back(vector<int>());

                // traverse through all the possible y-coordinates
                for (int y = 0; y <= 999; ++y)
                {

                    // if an element exists at the current x,y coordinates
                    if (m[x].find(y) != m[x].end())
                    {

                        // insert all the elements at this current x,y position, in order of ascending values (sorted automatically by set)
                        res.back().insert(res.back().end(), m[x][y].begin(), m[x][y].end());
                    }
                }
            }
        }
        return res;
    }

    void traverse(TreeNode *root, int x, int y, unordered_map<int, unordered_map<int, set<int>>> &m)
    {
        if (root == nullptr)
            return;

        m[x][y].insert(root->val);

        traverse(root->left, x - 1, y + 1, m);
        traverse(root->right, x + 1, y + 1, m);
    }
};