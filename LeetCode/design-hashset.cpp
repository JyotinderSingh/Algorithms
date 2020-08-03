// https://leetcode.com/problems/design-hashset/
// https://leetcode.com/problems/design-hashset/discuss/768467/2-Solution-or-Using-Boolean-Array-or-Chaining
// https://leetcode.com/problems/design-hashset/discuss/179164/C%2B%2B-97.97-without-a-massive-array-or-using-a-map-BST

class MyHashSet
{
    vector<bool> a;

public:
    /** Initialize your data structure here. */
    MyHashSet()
    {
        a = vector<bool>(1000001, false);
    }

    void add(int key)
    {
        a[key] = true;
    }

    void remove(int key)
    {
        a[key] = false;
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key)
    {
        return a[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */