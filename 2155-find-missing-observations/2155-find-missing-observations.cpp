class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int mSum = 0, totalSum = (rolls.size()+n)*mean;
        for(int i : rolls) mSum += i;
        int nSum = totalSum - mSum;
        vector<int> ans;
        if(nSum < n*1 || nSum > n*6) return ans;
        ans = vector<int>(n);
        cout << nSum << "\n";
        for(int i=0; i<n; i++){
            int remElements = n-i-1;
            ans[i] = min(6, nSum - remElements);
            nSum -= ans[i];
        }
        return ans;
    }
};