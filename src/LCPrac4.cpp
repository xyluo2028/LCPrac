// LCPrac4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <deque>

using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        _stack.push_back(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int back = _stack.back();
        _stack.pop_back();
        return back;
    }

    /** Get the top element. */
    int top() {
        int back = _stack.back();
        return back;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return _stack.empty();
    }

private:
    deque<int> _stack;
};


int main()
{
    MyStack* obj = new MyStack();
    obj->push(1);
    int param_3 = obj->top();
    cout << param_3 << endl;
    cout << obj->empty() << endl;
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */