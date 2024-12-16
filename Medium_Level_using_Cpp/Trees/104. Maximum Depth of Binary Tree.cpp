// Problem: 104. Maximum Depth of Binary Tree
// Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

// Topics: Recursion, Depth-First Search, Binary Tree, Tree, Breadth-First Search, Iterator, 
// Queue, Binary Search Tree, Stack, Binary Search, Backtracking, Array, Dynamic Programming, 
// Graph, Linked List, Math, Interactive, Divide and Conquer, Greedy, Binary Indexed Tree, 
// Doubly-Linked List, Memoization, Counting, Hash Table, Brainteaser, Concurrency, Sorting, 
// Monotonic Queue, Bit Manipulation, Union Find, Segment Tree

// Time Complexity:
// Recursive - 
// Iterative - 

// Space Complexity:
// Recursive - 
// Iterative - 
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

// Recursive Solution - DFS

class Solution {
    private:
    int calculateMaxDepth(TreeNode* p){
        if(!p) return 0;
        return max(calculateMaxDepth(p->left), calculateMaxDepth(p->right)) + 1;
    }
public:
    int maxDepth(TreeNode* root) {
        return calculateMaxDepth(root);
    }
};

// Iterative Solution - BFS

