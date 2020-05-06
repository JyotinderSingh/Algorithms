// https://leetcode.com/problems/intersection-of-two-arrays-ii/
class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> res;
        unordered_map<int, int> seen;
        for (int i = 0; i < nums1.size(); ++i)
        {
            seen[nums1[i]]++;
        }
        for (int i = 0; i < nums2.size(); ++i)
        {
            if (seen[nums2[i]] > 0)
            {
                res.push_back(nums2[i]);
                seen[nums2[i]]--;
            }
        }
        return res;
    }
};

// ALTERNATE APPROACH
class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> res;
        map<int, int> m1;
        for (int i = 0; i < nums1.size(); ++i)
        {
            m1[nums1[i]]++;
        }
        map<int, int> m2;
        for (int i = 0; i < nums2.size(); ++i)
        {
            m2[nums2[i]]++;
        }
        auto x = m1.begin();
        auto y = m2.begin();
        while (x != m1.end() && y != m2.end())
        {
            if (x->first == y->first)
            {
                int occurances = min(x->second, y->second);
                for (int i = 0; i < occurances; ++i)
                {
                    res.push_back(x->first);
                }
                x++, y++;
            }
            else if (x->first < y->first)
            {
                x++;
            }
            else
            {
                y++;
            }
        }
        return res;
    }
};