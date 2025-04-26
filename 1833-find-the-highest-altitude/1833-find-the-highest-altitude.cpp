class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0, prfx = 0;
        for(int i : gain) ans = max(ans, prfx += i);
        return ans;
    }
};