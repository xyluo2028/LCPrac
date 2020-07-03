// LCPrac3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* tracer = nullptr;
        ListNode* tracer1 = nullptr;
        ListNode* tracer2 = nullptr;
        if (head == NULL || head->next == NULL) return head;
        if ((head->next)->next == NULL) {
            tracer1 = head->next;
            tracer1->next = head;
            head->next = NULL;
            return tracer1;
        }
        tracer = head;
        tracer1 = head->next;
        tracer2 = tracer1->next;
        tracer->next = NULL;
        tracer1->next = tracer;
        while (true) {
            tracer = tracer2->next;
            tracer2->next = tracer1;
            if (tracer == NULL) {
                return tracer2;
            }
            tracer1 = tracer->next;
            tracer->next = tracer2;
            if (tracer1 == NULL) {
                return tracer;
            }
            tracer2 = tracer1->next;            
            tracer1->next = tracer;
            if (tracer2 == NULL) {
                return tracer1;
            }
        }

    }

};

int main()
{
    ListNode* head = new ListNode(0);
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    head->next = n1;
    n1->next = n2;
    n2->next = n3;
    Solution solution;
    ListNode* newhead;
    newhead = solution.reverseList(head);
    cout << newhead->val << endl;
    cout << (newhead->next)->val << endl;
    delete head;
    delete n1;
    delete n2;
    delete n3;
}

