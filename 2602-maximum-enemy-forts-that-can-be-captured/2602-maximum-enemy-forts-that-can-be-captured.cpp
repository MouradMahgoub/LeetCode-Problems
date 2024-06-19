class Solution {
public: 
    int captureForts(vector<int>& forts) {
        int ans=0;
        for(int l=0, r=0; r<forts.size(); r++){
            if(forts[r]){
                if(forts[l] == -forts[r]) ans = max(ans, r-l-1);
                l = r;
            }
        }
        return ans;
    }
};