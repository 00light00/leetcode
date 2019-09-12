/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
 *
 * https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (35.83%)
 * Likes:    842
 * Dislikes: 463
 * Total Accepted:    322.1K
 * Total Submissions: 899.1K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, find its minimum depth.
 * 
 * The minimum depth is the number of nodes along the shortest path from the
 * root node down to the nearest leaf node.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * return its minimum depth = 2.
 * 
 */
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
    int minDepth(TreeNode* root) {
        int re = 0;
        if (root) {
            if (!root->left && !root->right) {
                re = 1;
            }
            else if (!root->left)
                re = minDepth(root->right) + 1;
            else if (!root->right)
                re = minDepth(root->left) + 1;
            else
                re = min(minDepth(root->left), minDepth(root->right)) + 1;
            // printf("%d %d\n", root->val, re);
        }
        return re;
    }
};

