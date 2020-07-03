/** LCPrac15.cpp : This file contains the 'main' function. Program execution begins and ends there.
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
链接：https ://leetcode-cn.com/problems/add-two-numbers
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
**/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        int unit = 0;
        ListNode* result = new ListNode(0);
        ListNode* tracer0 = result;
        ListNode* tracer1 = result;
        int val_l1;
        int val_l2;
        while (true) {
            val_l1 = (l1 == NULL) ? 0 : l1->val;
            val_l2 = (l2 == NULL) ? 0 : l2->val;
            if (l1 == NULL && l2 == NULL) {
                if (unit == 0) {
                    delete tracer0;
                    tracer1->next = NULL;
                    break;
                }
                else {
                    tracer0->val = 1;
                    break;
                }
            }
            tracer0->next = new ListNode(0);
            tracer0->val = unit + val_l1 + val_l2;
            if (tracer0->val >= 10) {
                unit = 1;
                tracer0->val -= 10;
            }
            else unit = 0;
            tracer1 = tracer0;
            tracer0 = tracer0->next;
            if(l1 != NULL) l1 = l1->next;
            if(l2 != NULL) l2 = l2->next;
        }
        return result;
    }
};

int main()
{
    ListNode* test1 = new ListNode(1);

    ListNode* test2 = new ListNode(9);
    test2->next = new ListNode(9);

    Solution solve;
    ListNode* result = solve.addTwoNumbers(test1, test2);

    ListNode* tracer = test1;
    while (tracer !=NULL ) {
        tracer = test1->next;
        delete test1;
        test1 = tracer;
    }

    tracer = test2;
    while (tracer != NULL) {
        tracer = test2->next;
        delete test2;
        test2 = tracer;
    }

    tracer = result;
    while (tracer != NULL) {
        tracer = result->next;
        cout << result->val << endl;
        delete result;
        result = tracer;
    }
}

