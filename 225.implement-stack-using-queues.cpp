/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 *
 * https://leetcode.com/problems/implement-stack-using-queues/description/
 *
 * algorithms
 * Easy (40.66%)
 * Likes:    383
 * Dislikes: 461
 * Total Accepted:    141.5K
 * Total Submissions: 347.7K
 * Testcase Example:  '["MyStack","push","push","top","pop","empty"]\n[[],[1],[2],[],[],[]]'
 *
 * Implement the following operations of a stack using queues.
 * 
 * 
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * empty() -- Return whether the stack is empty.
 * 
 * 
 * Example:
 * 
 * 
 * MyStack stack = new MyStack();
 * 
 * stack.push(1);
 * stack.push(2);  
 * stack.top();   // returns 2
 * stack.pop();   // returns 2
 * stack.empty(); // returns false
 * 
 * Notes:
 * 
 * 
 * You must use only standard operations of a queue -- which means only push to
 * back, peek/pop from front, size, and is empty operations are valid.
 * Depending on your language, queue may not be supported natively. You may
 * simulate a queue by using a list or deque (double-ended queue), as long as
 * you use only standard operations of a queue.
 * You may assume that all operations are valid (for example, no pop or top
 * operations will be called on an empty stack).
 * 
 * 
 */
class MyStack {
public:
    int cnt;
    queue<int> que;
    /** Initialize your data structure here. */
    MyStack() {
        cnt = 0;
        while(!que.empty())
            que.pop();
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        que.push(x);
        cnt++;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        cnt--;
        for (int i = 0; i < cnt; ++i) {
            que.push(que.front());
            que.pop();
        }
        int re = que.front();
        que.pop();
        return re;
    }
    
    /** Get the top element. */
    int top() {
        int re = pop();
        push(re);
        return re;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return cnt == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

