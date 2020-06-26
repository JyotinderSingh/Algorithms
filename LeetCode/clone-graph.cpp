// https://leetcode.com/problems/clone-graph/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
    unordered_map<int, Node *> copiedNodes;

public:
    Node *cloneGraph(Node *node)
    {
        return clone(node);
    }

    Node *clone(Node *node)
    {
        if (!node)
            return nullptr;

        // If this node has already been copied, simply return a reference to it
        if (copiedNodes.find(node->val) != copiedNodes.end())
        {
            return copiedNodes[node->val];
        }

        // If this is a new node, instantiate it
        auto *newNode = new Node(node->val, vector<Node *>());

        // Add the newly created node into the lookup table to avoid extra copies in the future
        copiedNodes[node->val] = newNode;

        // Go through all the neighbours in the original node, and clone them, then add the copies
        // to the neighbours of the newNode
        for (const auto &neighbor : node->neighbors)
        {
            newNode->neighbors.push_back(clone(neighbor));
        }

        // Return the newly created node;
        return newNode;
    }
};