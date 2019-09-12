/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (32.28%)
 * Likes:    433
 * Dislikes: 1787
 * Total Accepted:    294.9K
 * Total Submissions: 913.4K
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word in the string.
 * 
 * If the last word does not exist, return 0.
 * 
 * Note: A word is defined as a character sequence consists of non-space
 * characters only.
 * 
 * Example:
 * 
 * 
 * Input: "Hello World"
 * Output: 5
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.size();
        int re = 0, last = 0;
        for (int j = 0; j <= len; ++j)
            if (s[j] == ' ' || !s[j]) {
                if (last < j)
                    re = j - last;
                last = j + 1;
                // printf("%d\n", j);
            }
        return re;
    }
};

