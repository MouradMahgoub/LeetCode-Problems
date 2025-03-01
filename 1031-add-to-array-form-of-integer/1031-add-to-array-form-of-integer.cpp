class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        int i = num.size()-1, carry = 0;
        while(i >=0 || k || carry){
            int res = (i>=0 ? num[i] : 0) + k%10 + carry; 
            ans.push_back(res%10);
            carry = res/10;
            k /= 10;
            i--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};