// Problem: 94. Binary Tree Inorder Traversal
// Link: https://leetcode.com/problems/binary-tree-inorder-traversal/description/
// Time Complexity: O(n)
// Space Complexity: O(1)
// Topics: Stack, Tree, Depth-First Search, Binary Tree
// Solution: // Iterative Approach
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
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* current = root;

        while (current) {
            if (!current->left) {
                // No left subtree, visit the current node and move to the right
                result.push_back(current->val);
                current = current->right;
            } else {
                // Find the inorder predecessor
                TreeNode* p = current->left;
                while (p->right && p->right != current) {
                    p = p->right;
                }

                if (!p->right) {
                    // Create a temporary link to the current node
                    p->right = current;
                    current = current->left;
                } else {
                    // Restore the tree structure and visit the current node
                    p->right = nullptr;
                    result.push_back(current->val);
                    current = current->right;
                }
            }
        }

        return result;
    }
};
