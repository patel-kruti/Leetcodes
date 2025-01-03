// Problem: 236. Lowest Common Ancestor of a Binary Tree
// Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
// Topics: Tree, Depth-First Search, Binary Tree
// Time Complexity: O(n) - visit every node
// Space Complexity: O(h) - height of the tree
// Solution:
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left && right){
            return root;
        }
        return left ? left : right;
    }
};