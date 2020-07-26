#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


class StringIterator {
public:
    StringIterator(string compressedString) {
        decodeStr = "";
        pos = 0;
        stage = 0;
        int tmpL;
        int para;
        for (size_t i = 0; i < compressedString.size(); i++)
        {
            if ((int)compressedString[i] > 57) decodeStr += compressedString[i];
            else {
                tmpL = 1;
                while ((int)compressedString[i + tmpL] <= 57 && (int)compressedString[i + tmpL] >= 48)tmpL++;
                para = stoi(compressedString.substr(i, tmpL));
                counts.push_back(para);
                i = i + tmpL - 1;
            }
        }
        SumTotal = 0;
        sumStages = counts[0];
        for (auto item:counts) {
            cout << item << ", ";
            SumTotal += item;
        }
        cout << endl;
        cout << decodeStr << endl;
    }

    char next() {
        if (!hasNext()) return ' ';
        
        while (pos >= sumStages) {
            sumStages += counts[++stage];
        }
        pos++;
        return decodeStr[stage];
    }

    bool hasNext() {
        if (pos == SumTotal) return false;
        else return true;
    }
private:
    string decodeStr;
    vector<int> counts;
    int pos;
    int stage;
    long SumTotal;
    int sumStages;
};

int main() {
    string test = "L3e2t1c1o1d1e11";
    StringIterator solve(test);
    cout << solve.next() << endl;
    cout << solve.next() << endl;
    cout << solve.next() << endl;
    cout << solve.next() << endl;
    cout << solve.next() << endl;
    cout << solve.next() << endl;
    cout << solve.next() << endl;
    //cout << stoi(test.substr(1, 1)) << endl;
} 
