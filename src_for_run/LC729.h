/*
good example of using std::set (sorted data structure), set.lower_bound(T), prev(std::iterator)
Input
["MyCalendar", "book", "book", "book"]
[[], [10, 20], [15, 25], [20, 30]]
Output
[null, true, false, true]  No overlapping!
*/

#include "common.h"

class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        const pair<int, int> event = {start, end};
        const auto lower_b = m_set.lower_bound(event);
        if (lower_b != m_set.end() && lower_b->first < end) {
            return false;
        }
        if (lower_b != m_set.begin()) {
            const auto pre_lower_b = prev(lower_b);
            if (pre_lower_b->second > start) {
                return false;
            }
        }
        m_set.insert(event);
        return true;
    }
    
private:
    set<pair<int, int>> m_set;
};
