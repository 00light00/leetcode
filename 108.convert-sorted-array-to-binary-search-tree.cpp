/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (52.51%)
 * Likes:    1383
 * Dislikes: 146
 * Total Accepted:    294.1K
 * Total Submissions: 560K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given an array where elements are sorted in ascending order, convert it to a
 * height balanced BST.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 * 
 * Example:
 * 
 * 
 * Given the sorted array: [-10,-3,0,5,9],
 * 
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following
 * height balanced BST:
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
 * 
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
    TreeNode* sortedArrayToBST(const vector<int>& nums) {
        TreeNode * re = NULL;
        int l = 0, r = nums.size();
        if (r != l) {
            re = buildtree(nums, l, r);
        }
        return re;
    }
    TreeNode* buildtree(const vector<int>& nums, int l, int r) {
        TreeNode* re = NULL;
        if (l != r) {
            int mid = (l + r) >> 1;
            re = new TreeNode(nums[mid]);
            if (l < mid)
                re->left = buildtree(nums, l, mid);
            if (mid + 1 < r)
                re->right = buildtree(nums, mid + 1, r); 
        }
        return re;
    }
};

