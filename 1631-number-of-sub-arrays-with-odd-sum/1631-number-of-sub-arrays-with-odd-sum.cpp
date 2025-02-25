class Solution {
public:
    int mod = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        vector<int> prfx(arr.size()+1, 0);
        for(int i=0; i<arr.size(); i++)
            prfx[i+1] = prfx[i] + arr[i];
        int ans = 0, even = 0, odd = 0;
        for(int num : prfx){
            if(num&1) {
                ans = (ans+even)%mod;
                odd++;
            } else {
                ans = (ans+odd)%mod;
                even++;
            } 
        }
        return ans;
    }
};