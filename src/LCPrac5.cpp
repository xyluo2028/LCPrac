// LCPrac5.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        ListNode* p0;
        ListNode* pb;
        ListNode* pf;
        ListNode* pout;
        if (l1->val > l2->val) {
            p0 = l2;
            pb = l1;
            pf = l1;
            pout = l2;
        }
        else
        {
            p0 = l1;
            pb = l2;
            pf = l2;
            pout = l1;
        }

        while (pf != NULL)
        {
            if ((p0->next)==NULL) {
                p0->next = pb;
                break;
            }
            else if ((p0->next)->val > pb->val)
            {
                pf = pb->next;
                pb->next = p0->next;
                p0->next = pb;
                pb = pf;
                p0 = p0->next;
            }
            else
            {
                p0 = p0->next;
            }
        }
        return pout;
    }
};



int main()
{
    ListNode* head = new ListNode(0);
    ListNode* n1 = new ListNode(3);
    ListNode* n2 = new ListNode(4);
    ListNode* n3 = new ListNode(8);
    head->next = n1;
    n1->next = n2;
    n2->next = n3;

    ListNode* head1 = new ListNode(1);
    ListNode* n11 = new ListNode(2);
    ListNode* n22 = new ListNode(5);
    head1->next = n11;
    n11->next = n22;

    Solution solution;
    ListNode* newhead;
    newhead = solution.mergeTwoLists(head, head1);
    cout << newhead->val << endl;
    cout << ((newhead->next)->next)->val << endl;
    delete head;
    delete n1;
    delete n2;
    delete n3;
    delete head1;
    delete n11;
    delete n22;
}
