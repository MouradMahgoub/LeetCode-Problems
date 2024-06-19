class Solution {
public: 
    int foo(vector<int>& forts) {
        int ans=0, cnt=0;
        for(int i=0; i<forts.size(); i++){
            if(forts[i] == 1){
                while(++i < forts.size() && forts[i] == 0) cnt++;
                if(i < forts.size() && forts[i] == -1) ans = max(ans, cnt);
                cnt = 0;
                i--;
            }
        }
        return ans;
    }
    int captureForts(vector<int>& forts) {
        int ans = 0;
        ans = foo(forts);
        reverse(forts.begin(), forts.end());
        ans = max(ans, foo(forts));
        return ans;
    }
};