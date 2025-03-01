class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        set<int> s;
        s.insert(0);
        int prfx = 0, ans = 0;
        for(int num : nums) {
            prfx += num;
            int temp = 0;
            if(prfx > 0) temp = *s.begin();
            else if(prfx < 0) temp = *s.rbegin();
            else temp = max(abs(*s.begin()), abs(*s.rbegin()));
            ans = max(ans, abs(prfx - temp));
            s.insert(prfx);
        }
        return ans;
    }
};