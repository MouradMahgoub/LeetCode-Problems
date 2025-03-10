class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        // int n = colors.size()-1;
        int l = 0, r = 1;
        int ans = 0;
        for(int i=0; i<k-1; i++) colors.push_back(colors[i]);
        while(r < colors.size()){
            if(colors[r] == colors[r-1]){
                l = r;
            }
            if(r-l+1 > k ) l++;
            if(r-l+1 == k) ans++;
            r++;
        }
        return ans;
    }
};