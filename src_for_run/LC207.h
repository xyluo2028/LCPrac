/*
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
*/

#include "common.h"

class Solution207BFS {
public:
    vector<vector<int>> m_graph;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < numCourses; ++i) {
            m_graph.push_back({});
        }
        vector<int> inDegree(numCourses);
        for (auto& path : prerequisites) {
            m_graph[path[0]].push_back(path[1]);
            ++inDegree[path[1]];
        }
        queue<int> mQ;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                mQ.push(i);
            }
        }
        
        if (mQ.empty()) return false;
        int sorted_num = 0;
        while(!mQ.empty()) {
            int tmp = mQ.front();
            mQ.pop();
            for (auto& n : m_graph[tmp]) {
                if (--inDegree[n] == 0) {
                    mQ.push(n);
                }
            }
            ++sorted_num;
        }
        
        return sorted_num == numCourses;
    }
};

class Solution207DFS {
public:
    vector<int> m_status;
    vector<vector<int>> m_graph;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        m_status = vector<int>(numCourses, 0);  // 0 = not found, 1 = found
        for (int i = 0; i < numCourses; ++i) {
            m_graph.push_back({});
        }
        for (auto& path : prerequisites) {
            m_graph[path[0]].push_back(path[1]);
        }
        unordered_set<int> tmp_path;
        for (int i = 0; i < numCourses; ++i) {
            if (m_status[i] != 0) continue;
            tmp_path.clear();
            if (dfsFindCircle(i, tmp_path)) return false;
        }
        return true;
    }
    
    bool dfsFindCircle(int node, unordered_set<int>& path) {
        if (m_graph[node].empty() || m_status[node] != 0) {
            m_status[node] = 1;
            return false;
        }
        path.emplace(node);
        for (auto n : m_graph[node]) {
            if(path.find(n) != path.end()){
                m_status[node] = 1;
                return true;
            }
        }
        for (auto n : m_graph[node]) {
            if (dfsFindCircle(n, path)) {
                m_status[node] = 1;
                path.erase(node);
                return true;
            }
        }
        path.erase(node);
        m_status[node] = 1;
        return false;
    }
    
};