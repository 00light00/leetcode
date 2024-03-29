/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 *
 * https://leetcode.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (47.13%)
 * Likes:    1033
 * Dislikes: 79
 * Total Accepted:    248.4K
 * Total Submissions: 524.8K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * Given a binary tree, return all root-to-leaf paths.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * 
 * Input:
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * Output: ["1->2->5", "1->3"]
 * 
 * Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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
    vector<string> re;
    vector<int> ans;
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root);
        return re;
    }

    void dfs(TreeNode* root) {
        if (root) {
            ans.push_back(root->val);
            if (!root->left && !root->right) {
                string str = "";
                for (auto it = ans.begin(); it != ans.end(); ++it) {
                    if (it != ans.begin())
                        str += "->";
                    str += to_string(*it);
                }
                re.push_back(str);
            }
            else {
                dfs(root->left);
                dfs(root->right);
            }
            ans.pop_back();
        }
    }
};

