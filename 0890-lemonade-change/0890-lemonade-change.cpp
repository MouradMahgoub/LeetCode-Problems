class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int c5=0, c10=0, c20=0;
        for(int bill : bills){
            if(bill == 5) c5++;
            else if(bill == 10) c10++;
            else c20++;
            if(bill == 5) continue;
            if(bill == 10) c5--;
            if(bill == 20){
                if(c10 > 0){
                    c10--; c5--;
                }else{
                    c5 -= 3;
                }
            }
            if(c5 < 0 || c10 < 0 || c20 < 0) return false;
        }
        return true;
    }
};