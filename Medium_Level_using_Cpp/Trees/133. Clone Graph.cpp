// Problem: 133. Clone Graph
// Link: https://leetcode.com/problems/clone-graph/description/
// Topics: Hash Table, Depth-First Search, Breadth-First Search, Graph
// Time Complexity:
// Recursive - O(V + E)
// Iterative - O(V + E)
// Space Complexity:
// Recursive - O(V) - Worst case - fully connected graph (all V nodes)
// Iterative - O(V) - Queue
// Solution:
// Iterative ----
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

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;

        unordered_map<Node*, Node*> cloneMap;
        cloneMap[node] = new Node(node->val);
        queue<Node*> q;
        q.push(node);

        while(!q.empty()){
            Node* currNode = q.front();
            q.pop();

            for(Node* neighbor: currNode->neighbors){
                // IF NEW NODE, THEN ADD IT IN MAP
                if(cloneMap.find(neighbor) == cloneMap.end()){
                    cloneMap[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                // ADD NEIGHBORS OF CURRENT NODE 
                cloneMap[currNode]->neighbors.push_back(cloneMap[neighbor]);
            }
        }

        // REFERENCE OF NEW CLONED GRAPH
        return cloneMap[node];
    }
};


// Recursive ----
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

class Solution {
    unordered_map<Node*, Node*> cloneMap;
    private:
    Node* dfs(Node* node){
        if(!node) return nullptr;

        //  NODE ALREADY EXISTS RETURN CLONED NODE
        if(cloneMap.find(node) != cloneMap.end()){
            return cloneMap[node];
        }

        // OTHERWISE: CREATE A CLONE OF CURRENT NODE
        cloneMap[node] = new Node(node->val);

        // ADD ALL NEIGHBORS OF CURRENT NODE IN THE MAP
        for(Node* neighbor: node->neighbors){
            cloneMap[node]->neighbors.push_back(dfs(neighbor));
        }

        // RETURN CLONE OF CURRENT NODE
        return cloneMap[node];

    }
public:
    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};
