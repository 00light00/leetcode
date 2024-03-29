/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (37.18%)
 * Likes:    3313
 * Dislikes: 155
 * Total Accepted:    685.3K
 * Total Submissions: 1.8M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */
class Solution {
public:
    bool isValid(const string& s) {
        bool re = false;
        int len = s.size();
        int p = 0;
        if (len == 0)
            return re = true;
        else if (len % 2 == 0) {
            re = dfs(p, s);
        }
        return re;
    }

    bool dfs(int &st, const string & s) {
        bool re = true;
        if (!s[st])
            return re = false;
        switch (s[st]) {
        case '(':
            re = dfs(++st, s);
            if (s[st++] != ')')
                return re = false;
            break;
        case '[':
            re = dfs(++st, s);
            if (s[st++] != ']')
                return re = false;
            break;
        case '{':
            re = dfs(++st, s);
            if (s[st++] != '}')
                return re = false;
            break;
        case ')':
        case ']':
        case '}':
            return re;
        default:
            return re = false;
        }
        return re;
    }
};

