#include "common.h"

class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList);
    }
    
    int next() {
        return vec[pos++];
    }
    
    bool hasNext() {
        return pos < vec.size();
    }
    
    void flatten(const vector<NestedInteger> &nestedList) {
        for (const NestedInteger& nI : nestedList) {
            if (nI.isInteger()) {
                vec.push_back(nI.getInteger());
            } else {
                flatten(nI.getList());
            }
        }
    }
private:
    vector<int> vec;
    int pos = 0;
};