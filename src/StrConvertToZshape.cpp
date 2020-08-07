class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        int Len = s.length();
        int iter = 0;
        string ans;
        while (true) //first row
        {
            if (2 * iter * (numRows - 1) < Len) {
                ans += s[2 * iter * (numRows - 1)];
                iter++;
            }
            else break;
        }
        iter = 0;
        for (size_t j = 1; j < numRows-1; j++)  //rows from 1 to N-2
        {
            while (true)
            {
                if (2 * iter * (numRows - 1) + j < Len) {
                    ans += s[2 * iter * (numRows - 1) + j];
                    iter++;
                }
                else break;
                if (2 * iter * (numRows - 1) - j < Len) {
                    ans += s[2 * iter * (numRows - 1) - j];
                }
                else break;
            }
            iter = 0;
        }
        iter = 0;
        while (true) //last row 
        {
            if ((2 * iter +1) * (numRows - 1)  < Len) {
                ans += s[(2 * iter + 1) * (numRows - 1)];
                iter++;
            }
            else break;
        }
        return ans;

    }
};
