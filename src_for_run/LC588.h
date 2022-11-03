/*
Input
["FileSystem", "ls", "mkdir", "addContentToFile", "ls", "readContentFromFile"]
[[], ["/"], ["/a/b/c"], ["/a/b/c/d", "hello"], ["/"], ["/a/b/c/d"]]
Output
[null, [], null, null, ["a"], "hello"]
*/

#include "common.h"

class FileTrie {
public:
    FileTrie() {
        m_isfile = false;
        m_filecontent = "";
    }
    
    virtual ~FileTrie() {
        
    }
    
    void makeSub(string name, bool isFile) {
        if (m_subs[name] != nullptr) return; // sub dir or file exist;
        m_subs[name] = new FileTrie();
        m_subs[name]->setIsFile(isFile);
    }
    
    FileTrie* getSub(string name) {
        if (m_subs[name] != nullptr) {
            return m_subs[name];
        }
        return nullptr;
    }
    
    void setIsFile(bool isFile) {
        m_isfile = isFile;
    }
    
    bool getIsFile() {
        return m_isfile;
    }
    
    void setFileContent(string content) {
        m_filecontent += content;
    }
    
    string getFileContent() {
        return m_filecontent;
    }
    
    vector<string> listSubs() {
        vector<string> ans;
        if (!m_isfile) {
            for (auto& p : m_subs) {
                ans.push_back(p.first);
            }
        } 
        return ans;
    }
    
private:
    bool m_isfile;
    map<string, FileTrie*> m_subs;
    string m_filecontent;
};

class FileSystem {
public:
    FileSystem() {
        root = new FileTrie();
    }
    
    vector<string> ls(string path) {
        if (path.compare("/") == 0) {
            return root->listSubs();
        }
        FileTrie* node = moveToBottom(path);
        int pos = path.find_last_of("/");
        string dirname = path.substr(pos + 1);
        vector<string> ans;
        if (node == nullptr) {
            return ans;
        }
        if (node->getIsFile()) {
            ans.push_back(dirname);
        } else {
            return node->listSubs();
        }
        return ans;
    }
    
    void mkdir(string path) {
        FileTrie* node = moveToBottom(path);
    }
    
    void addContentToFile(string filePath, string content) {
        FileTrie* node = moveToBottom(filePath);
        node->setIsFile(true);
        node->setFileContent(content);
    }
    
    string readContentFromFile(string filePath) {
        FileTrie* node = moveToBottom(filePath);
        return node->getFileContent();
    }
private:
    FileTrie* moveToBottom(string& path) {
        int start_p = 1;
        int slash_p = path.find("/", start_p);
        FileTrie* node = root;
        string dirname = "";
        while(slash_p != string::npos){
            dirname = path.substr(start_p, slash_p - start_p);
            if (node->getSub(dirname) == nullptr) {
                node->makeSub(dirname, false);
            }
            node = node->getSub(dirname);
            start_p = slash_p + 1;
            slash_p = path.find("/", start_p);
        }
        dirname = path.substr(start_p);
        if (node->getSub(dirname) == nullptr) {
            node->makeSub(dirname, false);
        }
        node = node->getSub(dirname);
        return node;
    }
    
    FileTrie* root;
};