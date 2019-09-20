/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (48.13%)
 * Likes:    844
 * Dislikes: 162
 * Total Accepted:    248.8K
 * Total Submissions: 515.5K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the bottom-up level order traversal of its
 * nodes' values. (ie, from left to right, level by level from leaf to root).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its bottom-up level order traversal as:
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<pair<int, TreeNode*> > que;
        int level = 1;
        vector<vector<int> > re;
        vector<int> relevel;
        que.push(make_pair(0, root));
        while (!que.empty()) {
            TreeNode* now = que.front().second;
            if (now) {
                if (que.front().first == level) {
                    level++;
                    re.push_back(relevel);
                    relevel.clear();
                }
                relevel.push_back(now->val);
                que.push(make_pair(level, now->left));
                que.push(make_pair(level, now->right));
            }
            que.pop();
        }
        if (relevel.size())
            re.push_back(relevel);
        reverse(re.begin(), re.end());
        return re;
    }
};

