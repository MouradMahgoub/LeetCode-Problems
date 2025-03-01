class Solution {
public:
    map<double, int> mp;
    Solution(vector<int>& w) {
        long sum = 0, prfx = 0;
        for(int ww : w) sum += ww;
        for(int i=0; i<w.size(); i++){
            if(w[i] == 0) continue;
            prfx += w[i];
            mp[double(prfx)/sum] = i;
        }
        for(auto [a, b] : mp)
            cout << a << " " << b << "\n";
    }
    
    int pickIndex() {
        return mp.upper_bound(double(rand())/RAND_MAX)->second;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */