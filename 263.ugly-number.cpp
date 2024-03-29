/*
 * @lc app=leetcode id=263 lang=cpp
 *
 * [263] Ugly Number
 *
 * https://leetcode.com/problems/ugly-number/description/
 *
 * algorithms
 * Easy (40.88%)
 * Likes:    269
 * Dislikes: 491
 * Total Accepted:    170.2K
 * Total Submissions: 415.7K
 * Testcase Example:  '6'
 *
 * Write a program to check whether a given number is an ugly number.
 * 
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
 * 
 * Example 1:
 * 
 * 
 * Input: 6
 * Output: true
 * Explanation: 6 = 2 × 3
 * 
 * Example 2:
 * 
 * 
 * Input: 8
 * Output: true
 * Explanation: 8 = 2 × 2 × 2
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 14
 * Output: false 
 * Explanation: 14 is not ugly since it includes another prime factor 7.
 * 
 * 
 * Note:
 * 
 * 
 * 1 is typically treated as an ugly number.
 * Input is within the 32-bit signed integer range: [−2^31,  2^31 − 1].
 * 
 */
class Solution {
public:
    bool isUgly(int num) {
        bool re = true;
        if (num < 1)
            return re = false;
        else {
            while (num != 1) {
                if (num%2 == 0)
                    num /= 2;
                else if (num%3 == 0)
                    num /= 3;
                else if (num%5 == 0)
                    num /= 5;    
                else
                    break;
            }
            if (num == 1)
                return re;
            else
                return re = false;
        }
    }
};

