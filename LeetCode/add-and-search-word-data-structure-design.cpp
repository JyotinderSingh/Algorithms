// https://leetcode.com/problems/add-and-search-word-data-structure-design/submissions/
struct TrieNode
{
    bool isLeaf;
    TrieNode *children[26];

    TrieNode()
    {
        isLeaf = false;
        for (int i = 0; i < 26; ++i)
        {
            children[i] = NULL;
        }
    }
};

class WordDictionary
{
    TrieNode *root;

public:
    /** Initialize your data structure here. */
    WordDictionary()
    {
        root = new TrieNode();
    }

    /** Adds a word into the data structure. */
    void addWord(string word)
    {
        auto ptr = root;

        for (int i = 0; i < word.size(); ++i)
        {
            int ch = word[i] - 'a';
            if (!ptr->children[ch])
            {
                ptr->children[ch] = new TrieNode();
            }
            ptr = ptr->children[ch];
        }
        ptr->isLeaf = true;
    }

    bool searchUtil(TrieNode *ptr, string word, int idx)
    {

        if (idx >= word.size())
        {
            return ptr->isLeaf;
        }

        if (word[idx] == '.')
        {
            bool flag = false;
            for (int i = 0; i < 26; ++i)
            {
                if (ptr->children[i])
                {
                    flag |= searchUtil(ptr->children[i], word, idx + 1);
                }
            }
            return flag;
        }
        else
        {
            if (!ptr->children[word[idx] - 'a'])
            {
                return false;
            }
            else
            {
                return searchUtil(ptr->children[word[idx] - 'a'], word, idx + 1);
            }
        }
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word)
    {
        return searchUtil(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */