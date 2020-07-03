// LCPrac18.cpp : This file contains the 'main' function. Program execution begins and ends there.

//Merge K sorted lists

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

void DeleteList(ListNode* del0, ListNode* del1) {
    while (del0 != NULL)
    {
        delete del0;
        if (del1 == NULL) break;
        else {
            del0 = del1;
            del1 = del1->next;
        }
        
    }
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> elems;
        int minidx;
        int minval;
        for (size_t i = 0; i < lists.size(); i++)
        {
            if (lists[i] == NULL) lists.erase(lists.begin() + i);
            else {
                elems.push_back(lists[i]->val);
                lists[i] = lists[i]->next;
            }
        }
        if (elems.empty()) return NULL;
        ListNode* result = new ListNode(0);
        ListNode* tracer = result;
        ListNode* result0 = result;
        while (!elems.empty())
        {
            minval = minelem(elems, minidx);
            cout << "minval" << ", " << minval << endl;
            result->val = minval;
            result->next = new ListNode(0);
            tracer = result;
            result = result->next;
            if (lists[minidx] != NULL) {
                elems[minidx] = lists[minidx]->val;
                lists[minidx] = lists[minidx]->next;
            }
            else {
                lists.erase(lists.begin() + minidx);
                elems.erase(elems.begin() + minidx);
            }
        }
        tracer->next = NULL;
        delete result;
        return result0;
    }

private:
    int minelem(vector<int> tmp, int& idx) {
        int result = 99999;
        for (size_t i = 0; i < tmp.size(); i++)
        {
            if (tmp[i] < result) {
                result = tmp[i];
                idx = i;
            }
        }
        return result;
    }
};

int main()
{
    ListNode* test1 = new ListNode(1);
    test1->next = new ListNode(4);
    (test1->next)->next = new ListNode(5);
    ListNode* test2 = new ListNode(1);
    test2->next = new ListNode(3);
    (test2->next)->next = new ListNode(4);
    ListNode* test3 = new ListNode(2);
    test3->next = new ListNode(6);
    vector<ListNode*> test = { test1,test2,test3 };
    Solution solve;
    ListNode* result = solve.mergeKLists(test);
    
 
    ListNode* deleter0 = result;
    ListNode* deleter1 = result->next;
    DeleteList(deleter0, deleter1);

}

