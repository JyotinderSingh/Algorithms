// https://leetcode.com/problems/insert-delete-getrandom-o1/
class RandomizedSet
{
    unordered_map<int, int> _positions;
    vector<int> _nums;

public:
    /** Initialize your data structure here. */
    RandomizedSet()
    {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        if (_positions.count(val) != 0)
        {
            return false;
        }
        _nums.push_back(val);
        _positions[val] = _nums.size() - 1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        if (_positions.count(val) != 0)
        {
            int pos = _positions[val];
            _nums[pos] = _nums[_nums.size() - 1];
            _positions[_nums[pos]] = pos;
            _nums.pop_back();
            _positions.erase(val);
            return true;
        }
        return false;
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        return _nums[rand() % _nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */