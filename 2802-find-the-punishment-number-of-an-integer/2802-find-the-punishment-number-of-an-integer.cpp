class Solution {
public:
    bool valid (string numSqr, int num) {
        if(numSqr == "" && num == 0) return true;
        for(int i=0; i<numSqr.size(); i++) {
            string left = numSqr.substr(0, i+1);
            string right = numSqr.substr(i+1);
            int leftNum = stoi(left);
            if(valid(right, num - leftNum)) return true;
        }
        return false;
    }

    int punishmentNumber(int n) {
        int ans = 0;
        for(int i=1; i<=n; i++)
            if(valid(to_string(i*i), i)) ans += i*i;
        return ans;
    }
};