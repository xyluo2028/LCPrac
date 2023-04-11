//  Design Bounded Blocking Queue
#include "common.h"

class BoundedBlockingQueue {
public:
    BoundedBlockingQueue(int capacity) {
        _cap = capacity;
    }
    
    void enqueue(int element) {
        {
            unique_lock<mutex> lock(_mtx);
            _cdv.wait(lock, [this](){return _q.size() < _cap;});
            _q.push(element);
        }
        _cdv.notify_all();
    }
    
    int dequeue() {
        int ans = 0;
        {
            unique_lock<mutex> lock(_mtx);
            _cdv.wait(lock, [this](){return !_q.empty();});
            ans = _q.front();
            _q.pop();
        }
        _cdv.notify_all();
        return ans;
    }
    
    int size() {
        lock_guard<mutex> lock(_mtx);
        return _q.size();
    }
private:
    queue<int> _q;
    condition_variable _cdv;
    mutex _mtx;
    int _cap;
};