/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 *
 * https://leetcode.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (38.58%)
 * Likes:    2071
 * Dislikes: 224
 * Total Accepted:    343.2K
 * Total Submissions: 888.3K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 * 
 * 
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
 * 
 * 
 * 
 * 
 */
class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> st;
    int minid;
    int tp;
    MinStack() {
        minid = -1;
        tp = -1;
    }
    
    void push(int x) {
        st.push_back(x);
        tp++;
        if (minid == -1)
            minid = 0;
        else {
            if (st[tp] < st[minid])
                minid = tp;
        }
    }
    
    void pop() {
        if (tp == minid) {
            if (tp != 0) {
                minid = 0;
                for (int i = 1; i < tp; ++i)
                    minid = st[i] < st[minid] ? i : minid;
            }
            else 
                minid = -1;
        }
        tp--;
        st.pop_back();
    }
    
    int top() {
        return st[tp];
    }
    
    int getMin() {
        return st[minid];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

