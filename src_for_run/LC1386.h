#include "common.h"

class Solution_slow {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        char RIGHT = 0b11110000;  // how to write binaray numbers 
        char MID = 0b00111100;
        char LEFT = 0b00001111;
        vector<char> table(n,0);
        for (auto pos : reservedSeats) {
            if (pos[1] > 1 && pos[1] < 10) table[pos[0]-1] |= (1<<(pos[1]-2));
        }
        int ans = 0;
        for (int i=0; i<n; ++i) {
            //cout << table[i] << endl;
            //cout << (table[i] & LEFT) << ", " << (table[i] & MID) << ", " <<(table[i] & RIGHT) << endl;
            if (!table[i]) ans += 2;
            else if ((table[i] & LEFT) == 0 || 
                    (table[i] & MID) == 0 ||
                    (table[i] & RIGHT) == 0) ans++;
        }
        return ans;
    }
};

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats)
    { 
        int ans = n*2;
        unordered_map<int, char> m;
    
        for (auto r : reservedSeats)  // only store reserved rows and seats
            if (r[1] > 1 && r[1] < 10) m[r[0]] |= 1<<(r[1]-2);
    
        for (auto seats : m)
        {  
            bool p1 = !(seats.second & 0b11110000);
            bool p2 = !(seats.second & 0b00111100);
            bool p3 = !(seats.second & 0b00001111);
        
            if (p1 && p3)
                continue;
            else if (p1 || p2 || p3)
                ans-=1;
            else
                ans-=2;
        }
    
        return ans;
    }
};