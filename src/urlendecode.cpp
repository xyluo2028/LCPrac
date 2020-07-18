//  input: https://leetcode.com/problems/design-tinyurl output: http://tinyurl.com/4e9iAk.
//ideas: random string, map original url to encoded url

#include <iostream>
#include <map>
#include <string>

using namespace std;

string randstr(int len)
{
    int i;
    string randstring = "";
    char tmp;
    for (i = 0; i < len; ++i)
    {
        switch ((rand() % 3))
        {
        case 1:
            tmp = 'A' + rand() % 26;
            randstring.push_back(tmp);
            break;
        case 2:
            tmp = 'a' + rand() % 26;
            randstring.push_back(tmp);
            break;
        default:
            tmp = '0' + rand() % 10;
            randstring.push_back(tmp);
            break;
        }
    }
    //str[++i] = '\0';
    return randstring;
}

class Solution {
public:
    string encode(string longUrl) {
        string code = randstr(5);
        int idx = 1;
        while (longUrl[longUrl.size()-idx]!='/') {
            idx++;
        }
        string suffix = longUrl.substr(longUrl.size() - idx+1, idx-1);
        string encoded = "http://";
        encoded = encoded+suffix+".com/"+code;
        hashT.emplace(code, longUrl);
        return encoded;
    }

    string decode(string shortUrl) {
        int idx = 1;
        while (shortUrl[shortUrl.size() - idx] != '/') {
            idx++;
        }
        string code = shortUrl.substr(shortUrl.size() - idx + 1, idx - 1);
        string decoded = hashT[code];
        return decoded;
    }

private:
    map<string, string> hashT;
};

int main()
{
    Solution solve;
    string test = "https://baidu.com/problems/design-tinyurl";
    string test1 = "https://google.com/problems/desdagn-tirl";
    string result0 = solve.encode(test);
    cout << result0 << endl;
    string result1 = solve.encode(test1);
    cout << result1 << endl;
}
