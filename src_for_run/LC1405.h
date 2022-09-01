/*
microsoft problem set No.1, good problem for using self-defined priority queue
*/

#include "common.h"

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        auto comp = [](pair<string, int>a, pair<string, int>b) {
            return a.second < b.second;
        };
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comp)> pq(comp);
        if (a > 0) pq.push({"a", a});
        if (b > 0) pq.push({"b", b});
        if (c > 0) pq.push({"c", c});
        string ans = "";
        while(true){
            if (pq.empty()) break;
            auto tmp = pq.top();
            pq.pop();
            //cout << tmp.first << "," << tmp.second << endl;
            if (!ans.empty() && tmp.first.compare(ans.substr(ans.size()-1)) == 0) {
                if (pq.empty()) break;
                else {
                    auto tmp2 = pq.top();
                    pq.pop();
                    pq.push(tmp);
                    tmp = tmp2;
                }
            }
            
            if (tmp.second >= 2) {
                ans += tmp.first + tmp.first;
                tmp.second  -= 2;
                if (!pq.empty() && pq.top().second > 0) {
                    auto tmp1 = pq.top();
                    //cout << tmp1.first << "," << tmp1.second << endl;
                    pq.pop();
                    if (tmp1.second > 2 && tmp1.second > tmp.second / 2) {
                        ans += tmp1.first + tmp1.first;
                        tmp1.second -= 2;
                    } else {
                        ans += tmp1.first;
                        tmp1.second--;
                    }                    
                    if(tmp1.second > 0)pq.push(tmp1);
                } else {
                    break;
                }
                if(tmp.second > 0)pq.push(tmp);
            } else {
                ans += tmp.first;
                tmp.second--;
            }
            //cout << ans << endl;
        }
        return ans;
    }
};


// cleaner solution
class Solution1 {
public:
    string longestDiverseString(int a, int b, int c) {
        //using max heap
        priority_queue<pair<int,char>>pq;
        if(a)
        pq.push({a,'a'});
        if(b)
        pq.push({b,'b'});
        if(c)
        pq.push({c,'c'});
        string ans="";
        while(pq.size()>1){
            pair<int,char>one = pq.top();pq.pop();
            pair<int,char>two = pq.top();pq.pop();
            if(one.first>=2){
                ans+=one.second;
                ans+=one.second;
                one.first-=2;
            }
            else{
                ans+=one.second;
                one.first-=1;
            }
            if(two.first>=2 && two.first>=one.first){
                ans+=two.second;
                ans+=two.second;
                two.first-=2;
            }
            else{
                ans+=two.second;
                two.first-=1;
            }
            if(one.first>0)
                pq.push(one);
            if(two.first>0)
                pq.push(two);
        }
        if(pq.empty())
            return ans;
        if(pq.top().first>=2){
            ans+=pq.top().second;
            ans+=pq.top().second;
        }
        else{
            ans+=pq.top().second;
        }
        return ans;
        
    }
};