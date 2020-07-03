// LCPrac36.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>

using namespace std;

class CQueue {
public:
    CQueue() {
        
    }

    void appendTail(int value) {
        _in_stack.push(value);
    }

    int deleteHead() {
        int elem;
        if (!_out_stack.empty()) {
            elem = _out_stack.top();
            _out_stack.pop();
        }
        else if (!_in_stack.empty()) {
            while(!_in_stack.empty())
            {
                _out_stack.push(_in_stack.top());
                _in_stack.pop();
            }
            elem = _out_stack.top();
            _out_stack.pop();
        }
        else elem = -1;
        return elem;
    }

private:
    stack<int> _in_stack;
    stack<int> _out_stack;
};

int main()
{
    CQueue* obj = new CQueue();
    obj->appendTail(1);
    obj->appendTail(2);
    obj->appendTail(3);
    obj->appendTail(4);
    obj->appendTail(5);
    obj->appendTail(6);

    cout << obj->deleteHead() << endl;
    cout << obj->deleteHead() << endl;
    cout << obj->deleteHead() << endl;
    cout << obj->deleteHead() << endl;

}

