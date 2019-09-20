/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (33.13%)
 * Likes:    1191
 * Dislikes: 3625
 * Total Accepted:    361.4K
 * Total Submissions: 1.1M
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 * 
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 * 
 * 
 * string convert(string s, int numRows);
 * 
 * Example 1:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 * 
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 * 
 */
class Solution {
public:
    string convert(string s, int numRows) {
        string re;
        int n = s.size();
        for (int i = 0; i * numRows < n; ++i) {
            re.push_back(s[i*2*(numRows - 1)]);
        }
        for(int j = 1; j < numRows; ++j) {
            for (int i = 0; i * numRows < n; ++i) {
                int id = i*numRows;
                if (i%2)
                    id += numRows - j;
                else
                    id += j;
                re.push_back(s[id]);
            }
        }
        for (int i = 0; i *numRows < n; ++i) {
            re.push_back(s[i*2*(numRows - 1) + numRows]);
        }
        return re;
    }
};

