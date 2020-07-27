bool comp(vector<int> a, vector<int> b) {
    if (a[0] < b[0]) return true;
    else return false;
}

class SolutionGood {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(), slots1.end(), comp);
        sort(slots2.begin(), slots2.end(), comp);
        int begin = 0;
        int end = 0;
        int trace = 0;
        vector<int> tmp;
        int i=0; int j=0;
        while (i < slots1.size() && j < slots2.size())
        {
            begin = slots1[i][0] > slots2[j][0] ? slots1[i][0] : slots2[j][0];
            end = slots1[i][1] < slots2[j][1] ? slots1[i][1] : slots2[j][1];
            if (end - begin >= duration) {
                tmp.resize(2);                    
                tmp[0] = begin;
                tmp[1] = begin + duration;
                return tmp;
            }
            else if(slots2[j][0] > slots1[i][0]){
                i++;
            } 
            else if(slots2[j][0] <= slots1[i][0]) j++;
        }
        return tmp;
    }
};

bool comp(vector<int> a, vector<int> b) {
    if (a[0] < b[0]) return true;
    else return false;
}

class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(), slots1.end(), comp);
        sort(slots2.begin(), slots2.end(), comp);
        int begin = 0;
        int end = 0;
        int trace = 0;
        vector<int> tmp;
        int i = 0; int j = 0;
        while (i < slots1.size() && j < slots2.size())
        {
            begin = slots1[i][0] > slots2[j][0] ? slots1[i][0] : slots2[j][0];
            end = slots1[i][1] < slots2[j][1] ? slots1[i][1] : slots2[j][1];
            if (end - begin >= duration) {
                tmp.resize(2);
                tmp[0] = begin;
                tmp[1] = begin + duration;
                return tmp;
            }
            else if (slots2[j][0] > slots1[i][0]) {
                i++;
            }
            else if (slots2[j][0] <= slots1[i][0]) j++;
        }
        return tmp;
    }
};
