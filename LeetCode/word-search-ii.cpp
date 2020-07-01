// https://leetcode.com/problems/word-search-ii/
struct TrieNode
{
    string isLeaf;
    TrieNode *children[26];
    TrieNode()
    {
        isLeaf = "";
        for (int i = 0; i < 26; ++i)
        {
            children[i] = nullptr;
        }
    }
};

class Solution
{
public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        vector<string> res;
        // Build the Trie
        TrieNode *root = buildTrie(words);

        // Traverse the graph and perform dfs
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                dfs(board, root, i, j, res);
            }
        }
        return res;
    }

    void dfs(vector<vector<char>> &board, TrieNode *root, int i, int j, vector<string> &res)
    {

        /*
        * The following cases are considered as invalid
        * 1. i or j being out of bounds
        * 2. root already having been explored (board[i][j] == "#")
        * 3. The currently selected cell on the board isn't present in the trie node
        */
        if (i < 0 || j < 0 || i == board.size() || j == board[0].size() || board[i][j] == '#' || root->children[board[i][j] - 'a'] == nullptr)
        {
            return;
        }

        // Move the root to the child node containing the current character
        root = root->children[board[i][j] - 'a'];

        // If this node is a leaf for the trie, add it to the answer
        if (!root->isLeaf.empty())
        {
            // push back the word that ends here into the result
            res.push_back(root->isLeaf);
            // set isLeaf for current word to an empty string
            // to avoid same word being found multiple times
            root->isLeaf = "";
        }

        // Mark this node as visited for current dfs
        char temp = board[i][j];
        board[i][j] = '#';

        // Explore neighbouring nodes
        int moveI[] = {0, 0, 1, -1}, moveJ[] = {1, -1, 0, 0};
        for (int k = 0; k < 4; ++k)
        {
            dfs(board, root, i + moveI[k], j + moveJ[k], res);
        }

        // Backtrack/Restore the original value of the node
        board[i][j] = temp;
    }

    TrieNode *buildTrie(vector<string> words)
    {
        // Initialize the root of the Trie
        TrieNode *root = new TrieNode();

        for (const auto &word : words)
        {
            auto current = root;
            for (const auto &w : word)
            {
                int ch = w - 'a';
                if (current->children[ch] == nullptr)
                {
                    current->children[ch] = new TrieNode();
                }
                current = current->children[ch];
            }
            current->isLeaf = word;
        }
        return root;
    }
};