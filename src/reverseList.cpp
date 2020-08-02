#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;
        stack<ListNode*> container;
        ListNode* tracer = head;
        while (tracer->next != NULL) {
            container.push(tracer);
            tracer = tracer->next;
        }
        head = tracer;
        while (!container.empty())
        {
            tracer->next = container.top();
            container.pop();
            tracer = tracer->next;
        }
        tracer->next = NULL;
        return head;
    }
};
