class Solution {
public:
    int numSplits(string s) {
        if (s.length() < 2) return 0;
        if (s.length() == 2) return s[0] == s[1] ? 0 : 1;
        int len = s.length();
        set<char> left;
        map<char, int> right_map;
        int result = 0;
        for (size_t i = 0; i < len; i++)
        {
            if (right_map.find(s[i]) == right_map.end()) right_map.emplace(s[i], 1);
            else right_map[s[i]]++;
        }
        for (size_t i = 0; i < len; i++)
        {
            left.emplace(s[i]);
            right_map[s[i]]--;
            if (right_map[s[i]] == 0) right_map.erase(s[i]);
            if (left.size() == right_map.size())result++;
            if (left.size() > right_map.size()) break;
        }
        return result;
    }
};
