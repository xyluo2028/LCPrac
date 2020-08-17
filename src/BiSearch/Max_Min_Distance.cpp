class Solution4 {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int upper = (position.back() - position.front()) / (m - 1);
        int lower = 1;
        int mid = 1; 
        int ans = 1;
        while (lower <= upper)
        {
            mid = lower + (upper - lower) * 0.5;
            if (verify(position, mid, m)) {
                lower = mid + 1;
                if (mid > ans) ans = mid;
            }
            else {
                upper = mid - 1;
                
            }
        }
        return ans;
    }

    bool verify(vector<int>& position, int dist, int m) {
        int prev = 0;
        int cnt = 1;
        for (size_t i = 1; i < position.size(); i++)
        {
            if (position[i] - position[prev] >= dist) {
                cnt++;
                prev = i;
            }
        }
        if (cnt >= m) return true;
        else return false;
    }
};
