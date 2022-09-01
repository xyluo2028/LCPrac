// basic implementation of trie

#include "common.h"

class TrieNode {
public:
    TrieNode() {
        trieNodeList.resize(26);
        for (int i = 0; i < 26; ++i) {
            trieNodeList[i] = nullptr;
        }
        _isEnd = false;
    }
    
    bool containsKey(char c) {
        return trieNodeList[c-'a'] != nullptr;
    }
    
    void putNode(char c, TrieNode* node) {
        trieNodeList[c-'a'] = node;
    }
    
    TrieNode* getNode(char c) {
        return trieNodeList[c-'a'];
    }
    
    bool isEnd() {
        return _isEnd;
    }
    
    void setEnd() {
        _isEnd = true;
    }
private:
    vector<TrieNode*> trieNodeList;
    bool _isEnd;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->containsKey(c)) {
                TrieNode* c_node = new TrieNode();
                node->putNode(c, c_node);
            }
            node = node->getNode(c);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        TrieNode* node = searchPrefix(word);
        return node != nullptr && node->isEnd();
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = searchPrefix(prefix);
        return node != nullptr;
    }
    
    TrieNode* searchPrefix(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->containsKey(c)) {
                node = node->getNode(c);
            } else {
                return nullptr;
            }
        }
        return node;
    }
private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */