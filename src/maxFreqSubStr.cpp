class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        map<string, int> my_list;
        string tmpStr;
        set<char> tmpSet;
        for (size_t i = 0; i <= s.size()-minSize; i++)
        {
            tmpStr = s.substr(i, minSize);
            if (my_list.find(tmpStr) != my_list.end()) my_list[tmpStr]++;
            else if (CheckS(tmpSet, tmpStr, maxLetters)) my_list.emplace(tmpStr, 1);
        }
        return FindMaxFeq(my_list);
    }
private:
    bool CheckS(set<char>& tmpSet, string& tmpStr, int&MaxLetters) {
        for (size_t i = 0; i < tmpStr.size(); i++)
        {
            tmpSet.emplace(tmpStr[i]);
            if (tmpSet.size() > MaxLetters) {
                tmpSet.clear();
                return false;
            }
        }
        tmpSet.clear();
        return true;
    }

    int FindMaxFeq(map<string, int>& MyList) {
        int maxfeq = 0;
        for (auto key:MyList)
        {
            cout << key.first << ", " << key.second << endl;;
            if (key.second > maxfeq) maxfeq = key.second;
        }
        return maxfeq;
    }
};
