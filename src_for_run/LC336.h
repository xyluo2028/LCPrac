/*
Traverse the array, build map. Key is the reversed string, value is index in array (0 based)

Edge case - check if empty string exists. It's interesting that for given words {"a", ""}, 
it's expected to return two results [0,1] and [1,0]. Since my main logic can cover [0, 1] 
concatenate("a", ""), so as to cover the other situation concatenate("", "a"), I need to traverse 
the words array again, find the palindrome word candidate except "" itself, and add pair("", palindrome 
word) to the final answer.

Main logic part. Partition the word into left and right, and see 1) if there exists a candidate in 
map equals the left side of current word, and right side of current word is palindrome, so 
concatenate(current word, candidate) forms a pair: left | right | candidate. 2) same for checking 
the right side of current word: candidate | left | right.
*/

#include "common.h"

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> dict;
        vector<vector<int>> ans;
        // build dictionary
        for(int i = 0; i < words.size(); i++) {
            string key = words[i];
            reverse(key.begin(), key.end());
            dict[key] = i;
        }
        // edge case: if empty string "" exists, find all palindromes to become pairs ("", self)
        if(dict.find("")!=dict.end()){
            for(int i = 0; i < words.size(); i++){
                if(i == dict[""]) continue;
                if(isPalindrome(words[i])) ans.push_back({dict[""], i}); // 1) if self is palindrome, here ans covers concatenate("", self) 
            }
        }
        for(int i = 0; i < words.size(); i++) {
            for(int j = 0; j < words[i].size(); j++) {
                string left = words[i].substr(0, j);
                string right = words[i].substr(j, words[i].size() - j);
                if(dict.find(left) != dict.end() && isPalindrome(right) && dict[left] != i) {
                    ans.push_back({i, dict[left]});     // 2) when j = 0, left = "", right = self, so here covers concatenate(self, "")
                }
                if(dict.find(right) != dict.end() && isPalindrome(left) && dict[right] != i) {
                    ans.push_back({dict[right], i});
                }
            }
        }
        return ans;        
    }
    bool isPalindrome(string str){
        int i = 0;
        int j = str.size() - 1; 
        while(i < j) {
            if(str[i++] != str[j--]) return false;
        }
        return true;
    }
};

class Solution1 {
public:
    struct TrieNode{
        vector<TrieNode*> _table;
        vector<int> index_with_pld;
        int _endNum;
        TrieNode() {
            _endNum = -1;
            _table.resize(26);
            for (int i = 0; i < 26; ++i) _table[i] = nullptr;
        }
    };
    vector<vector<int>> palindromePairs(vector<string>& words) {
        TrieNode* root = new TrieNode();
        // build trie
        for (int i = 0; i < words.size(); ++i) {
            string rv_word = words[i];
            reverse(rv_word.begin(), rv_word.end());
            TrieNode* node = root;
            for (int j = 0; j < rv_word.size(); ++j) {
                if (hasPalindromeRemain(rv_word, j)) {
                    node->index_with_pld.push_back(i);
                }
                char c = rv_word[j];
                if (node->_table[c-'a'] == nullptr) {
                    TrieNode* c_node = new TrieNode();
                    node->_table[c-'a'] = c_node;
                }
                node = node->_table[c-'a'];
            }
            node->_endNum = i;
        }
        
        //find pairs
        vector<vector<int>> ans;
        for (int i = 0; i < words.size(); ++i) {
            string word = words[i];
            TrieNode* node = root;
            for (int j = 0; j < word.size(); ++j) {
                if (node->_endNum != -1 && hasPalindromeRemain(word, j)) {
                    ans.push_back(vector<int>{i, node->_endNum});
                }
                char c = word[j];
                node = node->_table[c-'a'];
                if (node == nullptr) break;
            }
            if (node == nullptr) continue;
            if (node->_endNum != -1 && node->_endNum != i) {
                ans.push_back(vector<int>{i, node->_endNum});
            }
            for (int elem : node->index_with_pld) {
                ans.push_back(vector<int>{i, elem});
            }
        }
        return ans;
    }
    
    bool hasPalindromeRemain(string word, int start) {
        if (word.size() == 1) return true;
        int i = start;
        int j = word.size() - 1;
        while (j > i) {
            if (word[i] != word[j]) return false;
            ++i;
            --j;
        }
        return true;
    }
};

class Solution2 {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> result;
        unordered_map<string, int> dict;
        for(int i = 0; i < words.size(); i++) {
            dict[words[i]] = i;
        }
        for(int i = 0; i < words.size(); i++) {
            for(int j = 0; j <= words[i].length(); j++) {
                //check the suffix word
                if(is_palindrome(words[i], j, words[i].size() - 1)) {
                    /** the suffix word can be null to all the word **/
                    string suffix = words[i].substr(0, j);   // cover i to ""(empty str)
                    reverse(suffix.begin(), suffix.end());
                    if(dict.find(suffix) != dict.end() && i != dict[suffix]) {
                        result.push_back({i, dict[suffix]});
                    }
                }
                //check the prefix word 
                if(j > 0 && is_palindrome(words[i], 0, j - 1)) {
                    string prefix = words[i].substr(j);  // j to end, when j == lenth, prefix == ""
                    reverse(prefix.begin(), prefix.end());
                    if(dict.find(prefix) != dict.end() && dict[prefix] != i) {
                        result.push_back({dict[prefix], i});  // cover "" to i
                    }
                }
            }
        }
        return result;
    }
    
    bool is_palindrome(string& s, int start, int end) {
        while(start < end) {
            if(s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
        
    }
};