class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int ans = 0, m = flowerbed.size();
        for(int i=0; i<m; i++){
            if(flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) && (i == m-1 || flowerbed[i+1] == 0)){
                flowerbed[i] = 1;
                ans++;
            }
            if(ans >= n) return true;
        }
        return ans >= n;
    }
};
        // int prev1 = 0, aft1 = 0;
        // int curr = 0, add = 0, ans = 0;
        // for(int i=0; i<flowerbed.size(); i++){
        //     if(flowerbed[i] == 0) curr++;
        //     else {
        //         ans += (curr-prev1)/2;
        //         prev1 = 1;
        //         curr = 0;
        //     }
        //     if(ans >= n) return true;
        // }
        // ans += (curr-prev1+1)/2;
        // cout << ans ;
        // return ans >= n;