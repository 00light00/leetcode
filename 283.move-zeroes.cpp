/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 *
 * https://leetcode.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (55.07%)
 * Likes:    2380
 * Dislikes: 86
 * Total Accepted:    529K
 * Total Submissions: 958.5K
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * Given an array nums, write a function to move all 0's to the end of it while
 * maintaining the relative order of the non-zero elements.
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * 
 * Note:
 * 
 * 
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 * 
 */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p = 0, pnz = 0, n = nums.size();
        while (pnz < n && p < n) {
            if (nums[p] == 0) {
                pnz = max(p + 1, pnz);
                while (pnz < n && !nums[pnz]) pnz++;
                if (pnz < n)
                    swap(nums[p], nums[pnz]);
            }
            p++;
        }
    }
};

