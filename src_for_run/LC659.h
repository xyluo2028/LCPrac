// Split Array into Consecutive Subsequences
#include "common.h"

class SolutionPQ {
public:
    bool isPossible(vector<int>& nums) {
        auto comp = [](const pair<int, int>& p1, const pair<int, int>& p2) {
            if (p1.second != p2.second) {
                return p1.second > p2.second;
            } 
            return p1.second -p1.first > p2.second - p2.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        for (int& n : nums) {
            while (!pq.empty() && pq.top().second < n - 1) {
                if (pq.top().second - pq.top().first < 2) return false;
                pq.pop();
            }
            if (pq.empty() || pq.top().second == n) {
                pq.push({n, n});
            } else {
                pair<int, int> p = pq.top();
                pq.pop();
                p.second = n;
                pq.push(p);
            }
            cout << pq.top().first << " " << pq.top().second << endl;
        }
        while (!pq.empty()) {
            if (pq.top().second - pq.top().first < 2) return false;
            pq.pop();
        }
        return true;
    }
};

class SolutionHash {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> subseq;
        unordered_map<int, int> freq;
        for (int& n : nums) {
            freq[n]++;
        }
        for (int& n : nums) {
            if (freq[n] <= 0) continue;
            if (subseq[n-1] > 0) {
                subseq[n-1]--;
                subseq[n]++;
                freq[n]--;
            } else if (freq[n+1] > 0 && freq[n+2] > 0) {
                freq[n]--;
                freq[n+1]--;
                freq[n+2]--;
                subseq[n+2]++;
            } else {
                return false;
            }
        }
        return true;
    }
};
