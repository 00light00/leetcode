/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 *
 * algorithms
 * Easy (48.13%)
 * Likes:    3072
 * Dislikes: 139
 * Total Accepted:    579K
 * Total Submissions: 1.2M
 * Testcase Example:  '[7,1,5,3,6,4]'
 *
 * Say you have an array for which the i^th element is the price of a given
 * stock on day i.
 * 
 * If you were only permitted to complete at most one transaction (i.e., buy
 * one and sell one share of the stock), design an algorithm to find the
 * maximum profit.
 * 
 * Note that you cannot sell a stock before you buy one.
 * 
 * Example 1:
 * 
 * 
 * Input: [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit
 * = 6-1 = 5.
 * Not 7-1 = 6, as selling price needs to be larger than buying price.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 * 
 * 
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<int> st;
        st.reserve(len);
        int top = -1, summax = 0;
        for (int i = 0; i < len; ) {
            if (top < 0 || st[top] < prices[i]) {
                top++;
                st.push_back(prices[i++]);
            }
            else {
                printf("%d %d\n", st[top], st[0]);
                summax = max(summax, st[top--] - st[0]);
                st.pop_back();
            }
        }
        if (top >= 0)
            summax = max(summax, st[top] - st[0]);
        return summax;
    }
};

