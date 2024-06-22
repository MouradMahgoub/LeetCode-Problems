class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int k) {
        int ans=0, sum=0;
        for(int i=0; i<grumpy.size(); i++){
            if(grumpy[i] == 0){
                ans += customers[i];
                customers[i] = 0;
            }
        }
        sum = ans;
        for(int i=0; i<grumpy.size(); i++){
            if(i < k){
                ans += customers[i];
                sum += customers[i];
            }else{
                sum += customers[i];
                sum -= customers[i-k];
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};