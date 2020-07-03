// LCPrac23.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



#include <iostream>
#include <unordered_map>

using namespace std;

struct hashNode {
    int key;
    int val;
    hashNode* prev;
    hashNode* next;
    hashNode(int x, int y):key(x), val(y), next(NULL), prev(NULL) {}
};

class LRUCache {
public:
    LRUCache(int capacity) {
        _map.reserve(capacity);
        _capacity = capacity;
        _vol = 0;
    }

    ~LRUCache() {
        destroyCache();
    }

    int get(int key) {
        if (_map.find(key) == _map.end()) return -1;
        else {
            updateLRU(key);
            return _map[key]->val;
        }
    }

    void put(int key, int value) {
        if (_map.find(key) != _map.end()) {
            _map[key]->val = value;
            updateLRU(key);
        }
        else if (_vol >= _capacity) {
            replaceElem(key, value);
        }
        else {
            addElem(key, value);
        }
    }

private:
    void updateLRU(int key) {   //if an elem is called, put it on tail
        hashNode* tracer = _map[key];
        if (tracer == tail) return;
        if (tracer == head)
        {
            (tracer->next)->prev = NULL;
            head = tracer->next;
            tracer->next = NULL;
            tracer->prev = tail;
            tail->next = tracer;
            tail = tail->next;
            return;
        }
        (tracer->prev)->next = tracer->next;
        (tracer->next)->prev = tracer->prev;
        tracer->next = NULL;
        tracer->prev = tail;
        tail->next = tracer;
        tail = tail->next;
    }

    void replaceElem(int key, int value) {
        _map.erase(head->key);
        if (_vol==1)
        {
            delete head;
        }
        else {
            head = head->next;
            delete head->prev;
            head->prev = NULL;
        }
        _vol--;
        addElem(key, value);
    }

    void addElem(int key, int value) {
        if (_vol==0)  //first elem
        {
            head = new hashNode(key, value);
            tail = head;
            _map.emplace(key, tail);
        }
        else {
            tail->next = new hashNode(key, value);
            (tail->next)->prev = tail;
            tail = tail->next;
            _map.emplace(key, tail);
        }
        _vol++;
    }

    void destroyCache() {
        if (_vol == 0) return;
        for (size_t i = 0; i < _vol-1; i++)
        {
            _map.erase(head->key);
            head = head->next;
            delete head->prev;
            head->prev = NULL;
        }
        delete head;
    }

    unordered_map<int, hashNode*> _map;
    hashNode* head;
    hashNode* tail;
    int _capacity;
    int _vol;
};

int main()
{
    LRUCache* obj = new LRUCache(2);
    obj->put(2, 1);
    obj->put(1, 1);
    obj->put(2, 3);
    obj->put(4, 1);
    int getter = obj->get(1);
    cout << "getter: " << getter << endl;
    getter = obj->get(2);
    cout << "getter: " << getter << endl;
    delete obj;
}

//["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
//[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
//[null,null,null,1,null,-1,null,-1,3,4]
//["LRUCache", "put", "put", "put", "put", "get", "get"]
//[[2], [2, 1], [1, 1], [2, 3], [4, 1], [1], [2]]