class Solution {
public:
    bool increasingTriplet(vector<int>& v) {
        int n = v.size();
        vector<int> prevMin(n);
        vector<int> nextMax(n);
        int currMin = 1e9;
        for(int i=0; i<n; i++) {
            prevMin[i] = currMin;
            currMin = min(currMin, v[i]);
        }
        int currMax = -1e9;
        for(int i=n-1; i>=0; i--){
            nextMax[i] = currMax;
            currMax = max(currMax, v[i]);
        }
        for(int i=1; i<n-1; i++)
            if(v[i] > prevMin[i] && v[i] < nextMax[i]) 
                return true;
        return false;
    }
};