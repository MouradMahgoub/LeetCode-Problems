class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0){
            int temp = b;
            b = (b&a)<<1;
            a = a^temp;
        }
        return a;
    }
};