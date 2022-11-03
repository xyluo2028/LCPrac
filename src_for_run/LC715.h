/*
Input
["RangeModule", "addRange", "removeRange", "queryRange", "queryRange", "queryRange"]
[[], [10, 20], [14, 16], [10, 14], [13, 15], [16, 17]]
Output
[null, null, null, true, false, true]
*/

#include "common.h"

class RangeModule {
public:
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        //cout << "add" << endl;
        if (m_set.empty()) {
            m_set.emplace(left);
            m_set.emplace(right);
            return;
        }
        auto it_left = m_set.lower_bound(left);
        auto it_right = m_set.upper_bound(right);
        m_set.erase(it_left, it_right);
        m_set.insert(left);
        m_set.insert(right);
        it_left = m_set.lower_bound(left);
        
        int d_left = distance( m_set.begin(), it_left);
        //cout << "d_left " << d_left << endl;
        
        if (d_left % 2 == 1) {
            m_set.erase(it_left);
        }
        it_right = m_set.upper_bound(right);
        int d_right = distance(it_right, m_set.end());
        //cout << "d_right " << d_right << endl;
        if (d_right % 2 == 1) {
            m_set.erase(prev(it_right));
        }
    }
    
    bool queryRange(int left, int right) {
        if (m_set.empty()) return false;
        auto it_left = m_set.lower_bound(left);
        auto it_right = m_set.upper_bound(right);
        //cout << *it_left << " " << *it_right << endl;
        if (distance(m_set.begin(), it_left) % 2 == 1) {
            if (it_left == it_right) return true;
            if (*prev(it_right) == right && it_left == prev(it_right)) return true;
        } else {
            if (*it_left == left) {
                if (it_left == prev(it_right)) return true;
                if (*prev(it_right) == right && next(it_left) == prev(it_right)) return true;
            }
        }
        return false;
    }
    
    void removeRange(int left, int right) {
        //cout << "remove" << endl;
        auto it_left = m_set.lower_bound(left);
        auto it_right = m_set.upper_bound(right);
        m_set.erase(it_left, it_right);
        m_set.insert(left);
        m_set.insert(right);
        it_left = m_set.lower_bound(left);
        
        int d_left = distance(m_set.begin(), it_left);
        //cout << "d_left " << d_left << endl;
        
        if (d_left % 2 == 0) {
            m_set.erase(it_left);
        }
        it_right = m_set.upper_bound(right);
        
        int d_right = distance(it_right, m_set.end());
        //cout << "d_right " << d_right << endl;
        
        if (d_right % 2 == 0) {
            m_set.erase(prev(it_right));
        }
    }

private:
    set<int> m_set;
};
