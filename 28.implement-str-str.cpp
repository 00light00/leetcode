/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (32.83%)
 * Likes:    1025
 * Dislikes: 1479
 * Total Accepted:    486.3K
 * Total Submissions: 1.5M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 * 
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 * Example 1:
 * 
 * 
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * 
 * 
 * Clarification:
 * 
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 * 
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 * 
 */
class Solution {
public:
    int strStr(const string& haystack, const string& needle) {
        int len1 = haystack.size(), len2 = needle.size();
        for(int i = 0; i <= len1 - len2; ++i) {
            int j = 0;
            for(; j < len2; ++j) {
                if (haystack[i + j] != needle[j])
                    break;
            }
            if (j == len2)
                return i;
        }
        return -1;
    }
};

