class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int len = grid.size();
        vector<int> mostRightOnes(len);
        for (size_t i = 0; i < len; i++)
        {
            for (int j = len-1; j >= 0; j--)
            {
                if (grid[i][j] == 1) {
                    mostRightOnes[i] = j;
                    break;
                }                
            }
        }
        vector<int> RightOnesCpy = mostRightOnes;
        sort(RightOnesCpy.begin(), RightOnesCpy.end());
        for (size_t i = 0; i < len; i++)
        {
            if (RightOnesCpy[i] > i) return -1;
        }
        int ans = 0;
        size_t tmp;
        for (size_t i = 0; i < len-1; i++)
        {                          
            if (mostRightOnes[i] <= i) continue;
            else {
                for (size_t j = i; j < len; j++)
                {
                    if (mostRightOnes[j] <= i) {
                        tmp = j;
                        break;
                    }
                }
                for (size_t j = tmp; j > i; j--)
                {
                    swapElem(mostRightOnes, j, j - 1);
                    ans++;
                }
            }
        }
        return ans;
    }

private:
    void swapElem(vector<int>& vect, size_t idx, size_t idx1) {
        size_t tmp;
        tmp = vect[idx];
        vect[idx] = vect[idx1];
        vect[idx1] = tmp;
        return;
    }
};
