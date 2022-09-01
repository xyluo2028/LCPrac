#include "common.h"

class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (monoStk.empty() || val < monoStk.top()){
            monoStk.push(val);
        } else {
            monoStk.push(monoStk.top());
        }
        mStk.push(val);
    }
    
    void pop() {
        monoStk.pop();
        mStk.pop();
    }
    
    int top() {
        return mStk.top();
    }
    
    int getMin() {
        return monoStk.top();
    }
    
    stack<int> mStk;
    stack<int> monoStk;
};