// LCPrac29.cpp : This file contains the 'main' function. Program execution begins and ends there.
//{"t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"}

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseWords(vector<char>& s) {
        if (s.empty()) return;
        int offset = 0;
        int iter1 = s.size() - 1;
        while (s[iter1] != ' ' && iter1 != 0) iter1--;
        if (iter1 == 0) return;
        while (true)
        {
            s.push_back(s[iter1]);
            //cout << s.back() << "123" << endl;
            s.erase(s.begin() + iter1);

            iter1--;
            while (s[iter1]!=' ' && iter1 !=0) {
                s.insert(s.end() - offset, s[iter1]);
                s.erase(s.begin() + iter1);

                iter1--;
                offset++;
            }
            if (iter1 == 0) {
                s.insert(s.end() - offset, s[iter1]);
                s.erase(s.begin());
                break;
            }
            offset = 0;
        }
        
    }
};

int main()
{
    Solution solve;
    vector<char> test = { 't','h', 'e', ' ', 'm', 'a', 'n', ' ', 'l', 'i', 'v', 'e' };
    solve.reverseWords(test);
    for (auto item : test) {
        cout << item << endl;
    }
}


