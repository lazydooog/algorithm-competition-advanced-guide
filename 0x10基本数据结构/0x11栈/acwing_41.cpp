/*
* @Description: 41. 包含min函数的栈 
* @Author: Xiaobin Ren
* @Date:   2020-07-21 13:04:17
* @Last Modified time: 2020-07-21 13:33:42
*/
class MinStack {
public:
    /** initialize your data structure here. */
    
    stack<int> stk, stk_min;
    
    MinStack() {
         
    }
    
    void push(int x) {
       stk.push(x);
       if(stk_min.size()) x = min(x, stk_min.top());
       stk_min.push(x);
    }
    
    void pop() {
        stk.pop();
        stk_min.pop();
    }
    
    int top() {
        return stk.top();     
    }
    
    int getMin() {
        return stk_min.top();    
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */