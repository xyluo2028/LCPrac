// LRU cache
// maintain a two direction linked list and a hash table, delete a list node, remove the corresponding pair in the table

#include "common.h"

struct MyListNode {
    int key;
    int val;
    MyListNode* next;
    MyListNode* prev;
    MyListNode() {
        key = 0;
        val = 0;
        next = nullptr;
        prev = nullptr;
    }
};


class LRUCache {
public:
    LRUCache(int capacity) {
        _capacity = capacity;
        _curLenth = 0;
        head = nullptr;
        tail = nullptr;
        _keyNodeHash.clear();
    }
    
    ~LRUCache() {
        while (_curLenth > 0) {
            removeNode();
        }
        _keyNodeHash.clear();
    }
    
    int get(int key) {
        if (_keyNodeHash.find(key) == _keyNodeHash.end()) return -1;
        moveToTail(key);
        return _keyNodeHash[key]->val;
    }
    
    void put(int key, int value) {
        if (_keyNodeHash.find(key) != _keyNodeHash.end()) {
            _keyNodeHash[key]->val = value;
            moveToTail(key);
        } else {
            if (_curLenth >= _capacity) {
                removeNode();
            }
            addNode(key, value);
        }
    }
private:
    void moveToTail(int key) {
        MyListNode* tmpNode = _keyNodeHash[key];
        if (!tmpNode->next) return;
        if (tmpNode->prev) { // tmp Node is not head
            tmpNode->prev->next = tmpNode->next;  // easier to maintain a 2 direction list and a single direction list
        } else {
            head = tmpNode->next;
        }
        tmpNode->next->prev = tmpNode->prev;
        tail->next = tmpNode;
        tmpNode->next = nullptr;
        tmpNode->prev = tail;
        tail = tail->next;
    }
    
    void addNode(int key, int value) {
        MyListNode* tmp = new MyListNode();
        tmp->val = value;
        tmp->key = key;
        if (_curLenth == 0) { // add first node
            head = tmp;
            tail = tmp;
        } else {
            tmp->prev = tail;
            tail->next = tmp;
            tail = tail->next;
        }
        _keyNodeHash[key] = tmp;
        _curLenth++;
    }
    
    void removeNode() { // only remove head;
        if (!head) return; // empty List
        _keyNodeHash.erase(head->key);   // don't forget to erase
        if (!head->next) { // head is the only node left
            delete head;
            _curLenth = 0;
        } else {
            MyListNode* tmp = head;
            head = head->next;
            delete tmp;
            head->prev = nullptr;
            _curLenth--;
        }
    }
    
    int _capacity;
    int _curLenth;
    unordered_map<int, MyListNode*> _keyNodeHash;
    MyListNode* head;
    MyListNode* tail;
};

/*
clean solution using STL list and unordered_map
class LRUCache {
public:
    int caps;
    list<pair<int,int>> mylist;
    unordered_map<int,list<pair<int,int>>::iterator> mymap;
    LRUCache(int capacity) {
        caps = capacity;
    }
    
    int get(int key) {
        auto it = mymap.find(key);
        if(it == mymap.end())
        {
            return -1;
        }
        auto it1 = it->second;
        mymap.erase(key);
        int val = it1->second;
        mylist.erase(it1);
        mylist.push_back({key,val});
        auto itr = mylist.end();
        mymap.insert({key,--itr});
        return val;
    }
    
    void put(int key, int value) {
        auto it = mymap.find(key);
        if(it == mymap.end())
        {
            pair<int,int> p = mylist.front();
            if(mylist.size() == caps)
            {
                mylist.pop_front();
                mymap.erase(p.first);
            }  
        }
        else
        {
            auto it1 = it->second;
            mylist.erase(it1);
            mymap.erase(key);
        }
        mylist.push_back({key,value});
        auto itr = mylist.end();
        mymap.insert({key,--itr});
    }
};

 */