/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (31.74%)
 * Likes:    5902
 * Dislikes: 1536
 * Total Accepted:    1M
 * Total Submissions: 3.2M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example:
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * re = new ListNode(0);
        ListNode * p = re;
        int flag = 0;
        while (l1) {
            int a1 = l1->val, a2 = 0;
            if (l2) {
                a2 = l2->val;
            }
            int tmp = a1 + a2 + p->val;
            flag =  tmp/10;
            p->val = tmp%10;
            p->next = new ListNode(flag);
            l1 = l1->next;
            l2 = l2->next;
            p = p->next;
        }
        while (l2) {
            int tmp = p->val + l2->val;
            flag = tmp/10;
            p->val = tmp%10;
            p->next = new ListNode(flag);
            l2 = l2->next;
            p = p->next;
        }
        if (p->val == 0)
            delete p;
        return re;
    }
};
