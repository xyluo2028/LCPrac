// LCPrac16.cpp : This file contains the 'main' function. Program execution begins and ends there.
// round list 
//

#include <iostream>
#include <set>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == NULL) return false;
        set <ListNode*> container;
        ListNode* tracer = head;
        bool result = false;
        while (true)
        {
            if (tracer->next == NULL) {
                result = false;
                break;
            }
            if (container.find(tracer) != container.end()) {
                result = true;
                break;
            }
            container.insert(tracer);
            tracer = tracer->next;

        }
        return result;
    }
    
};

int main()
{
    
}

