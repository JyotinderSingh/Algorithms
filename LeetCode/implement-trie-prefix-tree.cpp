// https://leetcode.com/problems/implement-trie-prefix-tree/

// You can achieve faster run times if you use an array instead of a vector to store the mappings to child nodes
struct TrieNode
{
    bool isLeaf;
    vector<TrieNode *> children;
    TrieNode()
    {
        isLeaf = false;
        children = vector<TrieNode *>(26, NULL);
    }
};

class Trie
{
    TrieNode *root;

public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        int n = word.size();

        auto p = root;
        if (!p)
        {
            return;
        }

        for (int i = 0; i < n; ++i)
        {
            int ch = word[i] - 'a';
            if (!p->children[ch])
            {
                p->children[ch] = new TrieNode();
            }
            p = p->children[ch];
        }
        p->isLeaf = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        int n = word.size();

        auto p = root;

        if (!p)
        {
            return false;
        }

        for (int i = 0; i < n; ++i)
        {
            int ch = word[i] - 'a';
            if (!p->children[ch])
            {
                return false;
            }
            p = p->children[ch];
        }
        if (p->isLeaf)
        {
            return true;
        }
        return false;
    }
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        // return searchUtil(root, prefix, 0, true);
        int n = prefix.size();

        auto p = root;

        if (!root)
        {
            return false;
        }

        for (int i = 0; i < n; ++i)
        {
            int ch = prefix[i] - 'a';
            if (!p->children[ch])
            {
                return false;
            }
            p = p->children[ch];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
