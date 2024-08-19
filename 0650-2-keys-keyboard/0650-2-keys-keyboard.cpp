class Solution {
public:
    int getMinSteps (int n) {
        unordered_map<int, int> prime_factors;
        for(int i=2; i<=n && n>1; i++){
            while(n%i == 0){
                prime_factors[i]++;
                n /= i;
            }
        }
        int ans=0;
        for(auto [factor, power] : prime_factors)
            ans += factor*power;
        return ans;
    }

    int minSteps(int n) {
        return getMinSteps(n);
    }
};