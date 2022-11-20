//Given the head of a linked list, return the list after sorting it in ascending order.

#include "common.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;
        head = sortList(head);
        slow = sortList(slow);
        return mergeTwoLists(head, slow);
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode res0 = ListNode(0);
        ListNode* trace = &res0;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                trace->next = list1;
                trace = trace->next;
                list1 = list1->next;
            } else {
                trace->next = list2;
                trace = trace->next;
                list2 = list2->next;
            }
        }
        if (!list1) {
            trace->next = list2;
        } else if (!list2) {
            trace->next = list1;
        }
        ListNode* res = res0.next;
        return res;
    }
    
};