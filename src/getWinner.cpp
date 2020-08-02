
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int wins = 0;
        int maxnum = findmax(arr);
        if (k > arr.size()) return maxnum;
        queue<int> myQ;
        int pos = arr[0];
        for (auto item : arr) {
            myQ.push(item);
            
        }
        myQ.pop();
        while (wins < k && pos!=maxnum)
        {
            if (pos>myQ.front()) {
                wins++;
                myQ.push(myQ.front());
                myQ.pop();
            }
            else {
                wins = 1;
                myQ.push(pos);
                pos = myQ.front();
                myQ.pop();
            }            
        }
        return pos;
    }
private:
    int findmax(vector<int> arr) {
        int ans = arr[0];
        for (auto item : arr )
        {
            if (item > ans) ans = item;
        }
        return ans;
    }
};
