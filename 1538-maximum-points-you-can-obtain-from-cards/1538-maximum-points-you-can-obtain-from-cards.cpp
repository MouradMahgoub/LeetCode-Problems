class Solution {
public:
    int maxScore(vector<int>& v, int k) {
        int ans=0, sum=0;
        for(int i=0; i<k; i++) sum += v[i];
        ans = sum;
        for(int i=0; i<k; i++){
            sum += v[v.size()-1-i];
            sum -= v[k-1-i];
            ans = max(ans, sum);
        }
        return ans;
    }
};