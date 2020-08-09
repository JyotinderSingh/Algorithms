// https://leetcode.com/problems/lru-cache/

class LRUCache
{
    int capacity;
    // key, value pair
    list<pair<int, int>> lruList;

    /*
    * hashmap for O(1) lookup to each list element,
    * keys map to iterator to the corresponding elements in the list
    */
    unordered_map<int, list<pair<int, int>>::iterator> hash;

    // Util to move a list node to the front
    void moveToFront(int key, int value)
    {
        /*
        * 1. remove the node from the list, using the element's iterator
        * 2. Create a new entry at the front of the list
        * 3. Map the hashmap key to the new iterator
        */
        lruList.erase(hash[key]);
        lruList.push_front({key, value});
        hash[key] = lruList.begin();
    }

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {

        // return -1 if key doesn't exist in cache
        if (hash.find(key) == hash.end())
        {
            return -1;
        }

        /*
        * 1. Move the cache entry to the front
        * 2. Return the value
        */
        int value = (*hash[key]).second;
        moveToFront(key, value);
        return (*hash[key]).second;
    }

    void put(int key, int value)
    {
        // If the key already exists in the database,
        // simply move its cache entry to the front and update the value if needed
        if (hash.find(key) != hash.end())
        {
            moveToFront(key, value);
        }
        else
        {

            /*
            * If the cache entry doesn't already exist:
            * 1. Add a new entry to the front of the cache
            * 2. Add a mapping to the entry in the hash table
            * 3. If the capacity is exceeded, remove the least recently used item
            */

            lruList.push_front({key, value});
            hash[key] = lruList.begin();
            if (hash.size() > capacity)
            {
                /*
                * notice that here is where you actually use the key value you stored in the lruList,
                * i.e. to remove the corrosponding entry in the hashtable
                */
                hash.erase(lruList.back().first);

                // Remove the entry from the lruList
                lruList.pop_back();
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */