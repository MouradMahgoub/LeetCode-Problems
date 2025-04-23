class Solution {
public:
    int count (int i) {
        int res = 0;
        while(i > 0) {
            res += i%10;
            i /= 10;
        }
        return res;
    }
    int countLargestGroup(int n) {
        unordered_map<int, int> mp;
        int largestSize = 0;
        for(int i=1; i<=n; i++){
            int sumDigits = count(i);
            largestSize = max(largestSize, ++mp[sumDigits]);
        }
        int ans = 0;
        for(auto [group, size] : mp){
            if(size == largestSize) ans++;
        }
        return ans;
    }
};