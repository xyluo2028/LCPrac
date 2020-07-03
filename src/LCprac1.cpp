// LCprac1.cpp : Delete List Node
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = CalculateLenth(head);
        cout << len << endl;
        if (len == n) return head->next;
        ListNode* n1 = head;
        int idx = 0;
        while (idx<len-n-1)
        {
            n1 = n1->next;
            idx++;
        }
        n1->next = (n1->next)->next;
        return head;
    }

private:
    int CalculateLenth(ListNode* head) {
        if (head == NULL) return 0;
        int len = 1;
        ListNode* n0 = head;
        while (n0->next != nullptr)
        {
            len++;
            n0 = n0->next;
        }
        return len;
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
    newhead = solution.removeNthFromEnd(head, 1);
    cout << ((newhead->next)->next)->val;
    delete head;
    delete n1;
    delete n2;
    delete n3;


}
