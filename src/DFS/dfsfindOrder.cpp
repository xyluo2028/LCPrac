class Solution {
public:
    vector<vector<int>> edges;
    vector<int> status;
    vector<int> path;
    bool flag;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> emptyvec;
        if(numCourses==0) return emptyvec;
        status.assign(numCourses, 0);
        edges.resize(numCourses);
        flag = true;
        for (auto item:prerequisites)
        {
            edges[item[0]].push_back(item[1]);
        }
        for (int i=0; i<numCourses; i++)
        {
            if (status[i] == 0) dfs(i);
            if (!flag) break;
        }
        
        if (!flag) return emptyvec;
        else return path;
    }
private:
    void dfs(int startNode) {
        status[startNode] = 1;
        if (edges[startNode].empty()) {
            status[startNode] = 2;
            path.push_back(startNode);
            return;
        }
        for (auto item : edges[startNode]) {
            if (status[item] == 1) {
                flag = false;
                return;
            }
            else if(status[item]==0)dfs(item);
            if (!flag) return;
        }
        status[startNode] = 2;
        path.push_back(startNode);
        return;
    }
};
