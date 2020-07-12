// LCPrac13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        int len = 0;
        Node* PnewList = new Node(head->val);
        Node* NewTracer = PnewList;
        Node* NewTracer1 = PnewList;
        Node* tracer = head;
        map<Node*, Node*> castNode;
        castNode[tracer] = PnewList;
        while (tracer->next != NULL) {
            tracer = tracer->next;
            PnewList->next = new Node(tracer->val);
            PnewList = PnewList->next;
            castNode.emplace(tracer, PnewList);
            len++;
        }
        tracer = head;
        PnewList = NewTracer;
        for (size_t i = 0; i < len; i++)
        {
            while (true)
            {
                if (tracer->random == NULL) {
                    NewTracer->random = NULL;
                    break;
                }
                else if (castNode[tracer->random] == NewTracer1) {
                    NewTracer->random = NewTracer1;
                    break;
                }
                NewTracer1 = NewTracer1->next;
            }
            tracer = tracer->next;
            NewTracer = NewTracer->next;
            NewTracer1 = PnewList;
        }
        return PnewList;

    }
};

int main()
{
    
}

