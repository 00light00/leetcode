/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (53.40%)
 * Likes:    852
 * Dislikes: 117
 * Total Accepted:    397.4K
 * Total Submissions: 741.7K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two strings s and t , write a function to determine if t is an anagram
 * of s.
 * 
 * Example 1:
 * 
 * 
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "rat", t = "car"
 * Output: false
 * 
 * 
 * Note:
 * You may assume the string contains only lowercase alphabets.
 * 
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your
 * solution to such case?
 * 
 */
class Solution {
public:
    bool isAnagram(string s, string t) {
        const int MAX = 255;
        int sn = s.size(), tn = t.size();
        if (sn != tn) return false;
        vector<int> cnt(MAX);
        for (const auto& i: s) {
            cnt[i]++;
        }
        for (const auto& i: t) {
            cnt[i]--;
        }
        for (int i = 0; i < MAX; ++i) {
            if (cnt[i])
                return false;
        }
        return true;
    }
};

