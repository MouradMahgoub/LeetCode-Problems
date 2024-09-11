class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt=0;
        int temp = start ^ goal;
        while(temp){
            cnt += (temp&1);
            temp >>= 1;
        }
        return cnt;
    }
};