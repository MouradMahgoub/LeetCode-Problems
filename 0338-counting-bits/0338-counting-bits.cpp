class Solution {
public:
    int countOnes (int x) {
        int cnt = 0;
        while(x != 0){
            cnt += (x&1 == 1);
            x >>= 1;
        }
        return cnt;
    }
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i=0; i<=n; i++)
            ans[i] = countOnes(i);
        return ans;
    }
};