#include "common.h"

class Solution {
public:
    struct TrieNode {
        vector<TrieNode*> table{vector<TrieNode*>(26, nullptr)};
        bool isEnd = false;
    };
    
    void insertWord(TrieNode* root, string& word) {
        for (char let : word) {
            if (root->table[let - 'a'] == nullptr) {
                root->table[let - 'a'] = new TrieNode();
            }
            root = root->table[let-'a'];
        }
        root->isEnd = true;
    }
    
    void recSearch(TrieNode* root, string& word, vector<string>& ans) {   //use reference(&) not copy !!! save huge memory
        if (ans.size() >= 3) return;
        if (root->isEnd) {
            ans.push_back(word);
        }
        for (int i = 0; i < 26; ++i) {
            if (!root->table[i]) continue;
            word.push_back((char)('a'+i));
            recSearch(root->table[i], word, ans);
            word.pop_back();
            if (ans.size() >= 3) return;
        }
        return;
    }
    
    vector<string> searchStartWith(TrieNode* root, string prefix) {
        for (auto c : prefix) {
            if (root->table[c-'a'] != nullptr) {
                root = root->table[c-'a'];
            } else {
                return {}; // no word start with
            }
        }
        vector<string> ans;
        
        recSearch(root, prefix, ans);
        return ans;
    }
    
    void deleteTrie(TrieNode* root) {
        for (int i = 0; i< 26; ++i) {
            if (root->table[i] != nullptr) deleteTrie(root->table[i]);
        }
        delete root;
    }    

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        TrieNode* root = new TrieNode();
        TrieNode* root_cpy = root;
        for (auto& prod : products) {
            insertWord(root_cpy, prod);
            root_cpy = root;
        }
        vector<vector<string>> ans;
        int len = searchWord.size();
        for (int i = 0; i < len; ++i) {
            vector<string> sub_ans = searchStartWith(root_cpy, searchWord.substr(0, i+1));
            root_cpy = root;
            ans.push_back(sub_ans);
        }
        deleteTrie(root);
        return ans;
    }
};

class Trie {
public:
    struct TrieNode {
        bool isEnd = false;
        vector<TrieNode*> table{vector<TrieNode*>(26, nullptr)};
    };
    Trie() {
        root_org = new TrieNode();
    }
    
    virtual ~Trie() {
        deleteTrie(root);
    }
    
    void deleteTrie(TrieNode* root) {
        for (int i = 0; i< 26; ++i) {
            if (root->table[i] != nullptr) deleteTrie(root->table[i]);
        }
        delete root;
    } 
    
    void insertWord(string& word) {
        root = root_org;
        for (char& let : word) {
            if (root->table[let - 'a'] == nullptr) {
                root->table[let - 'a'] = new TrieNode();
            }
            root = root->table[let-'a'];
        }
        root->isEnd = true;
    }
    
    void recSearch(TrieNode* root, string& word, vector<string>& ans) {
        if (ans.size() >= 3) return;
        if (root->isEnd) {
            ans.push_back(word);
        }
        for (int i = 0; i < 26; ++i) {
            if (!root->table[i]) continue;
            word += (char)('a'+i);
            recSearch(root->table[i], word, ans);
            word.pop_back();
            if (ans.size() >= 3) return;
        }
        return;
    }
    
    vector<string> searchStartWith(string &prefix) {
        root = root_org;
        for (auto& c : prefix) {
            if (root->table[c-'a'] != nullptr) {
                root = root->table[c-'a'];
            } else {
                return {}; // no word start with
            }
        }
        vector<string> ans;
        
        recSearch(root, prefix, ans);
        return ans;
    }
    
    TrieNode* root;
    TrieNode* root_org;
};

class Solution_opt {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie trie = Trie();
        for (auto& prod : products) {
            trie.insertWord(prod);
        }
        vector<vector<string>> ans;
        string prefix = "";
        for (auto& let : searchWord) {
            prefix += let;
            vector<string> sub_ans = trie.searchStartWith(prefix);
            ans.push_back(sub_ans);
        }
        return ans;
    }
};