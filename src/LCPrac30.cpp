

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string x_str = to_string(x);
        int len = x_str.size();
        int front = len-1;
        int back = 0;
        bool result = true;
        while (back < front)
        {
            if (x_str[back] != x_str[front])
            {
                result = false;
                break;
            }
            else {
                back++;
                front--;
            }
        }
        return result;
    }
};

int main()
{
    int input = 1;
    Solution solve;
    bool result = solve.isPalindrome(input);
    cout << result << endl;
}
