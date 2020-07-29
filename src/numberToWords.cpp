// LCPrac13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>

using namespace std;

map <int, string> NumToTxt = { {0, ""}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9,"Nine"}, {10, "Ten"},
    {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"},
    {20, "Twenty"}, {30, "Thirty"}, {40, "Forty"}, {50, "Fifty"}, {60, "Sixty"}, {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"} };


class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string result = "";
        string tmp_result = "";
        int tmp;
        int level = 0;
        if (num >= 1000)level++;
        if (num >= 1000000) level++;
        if (num >= 1000000000) level++;
        switch (level)
        {
        case 3:
            tmp = num / 1000000000;
            result += numberToWordsUnit(tmp);
            num = num % 1000000000;
            if (tmp != 0) {
                result += " Billion";
                if (num != 0) result += " ";
            }
            if (num == 0) break;
        case 2:
            tmp = num / 1000000;
            result += numberToWordsUnit(tmp);
            num = num % 1000000;
            if (tmp != 0) {
                result += " Million";
                if (num != 0) result += " ";
            }
            if (num == 0) break;
        case 1:
            tmp = num / 1000;
            result += numberToWordsUnit(tmp);
            num = num % 1000;
            if (tmp != 0) {
                result += " Thousand";
                if (num != 0) result += " ";
            }
            if (num == 0) break;
        case 0:
            result += numberToWordsUnit(num);
            break;
        }
        return result;
    }
private:
    string numberToWordsUnit(int num) {
        string result = "";
        int tmp;
        tmp = num / 100;
        result += (tmp!=0) ? (NumToTxt[tmp] + " " + "Hundred"):"";
        num = num % 100;
        if (tmp != 0 && num != 0) result += " ";
        if (num < 20) {
            result += (num != 0) ? (NumToTxt[num]) : "";
        }
        else {
            tmp = num / 10;
            result += (tmp != 0) ? (NumToTxt[tmp * 10]) : "";
            num = num % 10;
            if (tmp != 0 && num != 0) result += " ";
            result += NumToTxt[num];
        }
        

        
        return result;
    }
};

int main()
{
    Solution solve;
    string output = solve.numberToWords(1000010);
    cout << output << endl;
}

