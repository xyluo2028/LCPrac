// LCPrac30.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <set>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (headA == NULL || headB == NULL) return NULL;
        set<ListNode*> container;
        ListNode* tracer = headA;
        while(tracer != NULL){
            container.emplace(tracer);
            tracer = tracer->next;
        }
        tracer = headB;
        while (tracer!=NULL)
        {
            if (container.find(tracer) != container.end()) return tracer;
            tracer = tracer->next;
        }
        return NULL;
    }
};

int main()
{
    Solution solve;

}
