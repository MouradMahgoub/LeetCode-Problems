class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int> s(arr.begin(), arr.end());
        int ans = 0;
        for(int i=0; i<arr.size(); i++){
            for(int j=i+1; j<arr.size(); j++){
                int x1 = arr[i], x2 = arr[j];
                int len = 2;
                while(s.count(x1 + x2)){
                    len++;
                    ans = max(ans, len);
                    x2 = x1 + x2;
                    x1 = x2 - x1;
                }
            }
        }
        return ans;
    }
};