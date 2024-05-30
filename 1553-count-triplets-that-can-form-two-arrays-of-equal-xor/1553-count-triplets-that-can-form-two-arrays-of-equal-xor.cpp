class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int ans = 0;
        int prfx[arr.size()+5];
        prfx[0] = 0;
        for(int i=1; i<=arr.size(); i++) prfx[i] = prfx[i-1]^arr[i-1];
        for(int i=1; i<=arr.size()-1; i++)
            for(int j=i+1; j<=arr.size(); j++)
                for(int k=j; k<=arr.size(); k++){
                    int a = 0, b = 0;
                    a = prfx[j-1] ^ prfx[i-1];
                    b = prfx[k] ^ prfx[j-1];
                    if(a == b) ans++;
                }
        return ans;
    }
};