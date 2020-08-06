#include <iostream>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

class Solution {

public:
    map<int, vector<int>> container;
    vector<int> states;
    bool flag;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        states.resize(numCourses);
        flag = true;
        for (auto item:prerequisites)
        {
            states[item[0]] = 0;
            states[item[1]] = 0;
            if (container.count(item[0]) == 0) {
                vector<int> tmp;
                tmp.push_back(item[1]);
                container.emplace(item[0], tmp);
            }            
            else {
                container[item[0]].push_back(item[1]);
            }
        }
        for (int i=0; i<numCourses; i++)
        {
            if (states[i]!=2) dfs(i);
            if (!flag) return false;
        }
        return flag;
        
    }
private:
    void dfs(int start_node) {
        states[start_node] = 1;
        for (auto item: container[start_node])
        {
            cout << item << ": " << states[item] << endl;
            if (states[item]==1) {
                flag = false;
                return;
            }
            
            if(states[item]!=2) dfs(item);
        }
        states[start_node] = 2;
        return;
    }
};
int main() {
    Solution solve;
    vector<vector<int>> test = { {2,0}, {1,0}, {1,3}, {3,1}, {3,2} };
    bool result = solve.canFinish(4, test);
    cout << result << endl;
}
