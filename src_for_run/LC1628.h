#include "common.h"

class Node {
public:
    virtual ~Node () {};
    virtual int evaluate() const = 0;
protected:
    // define your fields here
};

class DigitNode : public Node {
public:
    DigitNode(int val) {
        m_val = val;
    }
    
    int evaluate() const override {
        return m_val;
    }
protected:
    int m_val;
};

class OpNode : public Node {
public:
    OpNode(string op) {
        m_op = op;
    }
    
    virtual ~OpNode() {
        delete m_left;
        delete m_right;
    }
    
    int evaluate() const override {
        switch(m_op[0]) {
            case '+':
                return m_left->evaluate() + m_right->evaluate();
            case '-':
                return m_left->evaluate() - m_right->evaluate();
            case '*':
                return m_left->evaluate() * m_right->evaluate();
            case '/':
                return m_left->evaluate() / m_right->evaluate();
            default:
                break;
        }
        return -1;
    }
    
    void set_left(Node* left) {
        m_left = left;
    }
    
    void set_right(Node* right) {
        m_right = right;
    }
    
protected:
    string m_op;
    Node* m_left;
    Node* m_right;
};

/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input 
 * and returns the expression tree represnting it as a Node.
 */

class TreeBuilder {
public:
    Node* buildTree(vector<string>& postfix) {
        stack<Node*> mStk;
        int N = postfix.size();
        for (auto& str : postfix) {
            if(isdigit(str[0])) {
                int node_val = atoi(str.c_str());
                DigitNode* tmp = new DigitNode(node_val);
                mStk.push(tmp);
            } else {
                OpNode* tmp = new OpNode(str);
                tmp->set_right(mStk.top());
                mStk.pop();
                tmp->set_left(mStk.top());
                mStk.pop();
                mStk.push(tmp);
            }
        }
        return mStk.top();
    }
};


/**
 * Your TreeBuilder object will be instantiated and called as such:
 * TreeBuilder* obj = new TreeBuilder();
 * Node* expTree = obj->buildTree(postfix);
 * int ans = expTree->evaluate();
 */