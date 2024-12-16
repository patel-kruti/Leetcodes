// Problem: 101. Symmetric Tree
// Link: https://leetcode.com/problems/symmetric-tree/description/
// Topics: Recursion, Binary Tree, Tree, Depth-First Search, 
//          Breadth-First Search, Iterator, Queue, Stack, Binary Search Tree, 
//          Binary Search, Two Pointers, Backtracking, Binary Indexed Tree, 
//          Array, Interactive, Divide and Conquer, Linked List, 
//          Dynamic Programming, Graph, String, Hash Table, Minimum Spanning Tree, 
//          Trie, Greedy, String Matching, Math, Counting, Bit Manipulation
// Time Complexity: 
// Recursive - O(n) - Every Node visited
// Iterative - O(n) - Every Node visited
// Space Complexity:
// Recursive - O(h) - height of the tree (stack space) - Uses Stack for Recursion
// Iterative - O(w) - width of the tree
// Solution: 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Recursive Approach

class Solution {
private:
    bool testSymmetry(TreeNode* left, TreeNode* right){
        if(!left && !right){
            return true;
        }
        if(!left || !right){
            return false;
        }
        return left->val == right->val && testSymmetry(left->left, right->right) && testSymmetry(left->right, right->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        return root == nullptr || testSymmetry(root->left, root->right);
    }
};

// Iterative Solution
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);

        while(!q.empty()){
            TreeNode* left = q.front(); q.pop();
            TreeNode* right = q.front(); q.pop();

            if(!left && !right) continue;
            if(!left || !right || left->val != right->val) return false;

            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }

        return true;
    }
};