class Solution {
public:
    bool isUgly(int n) {
        for(int i=2; i<=5 && n; i++)
            while(n%i == 0) n /= i;
        return n == 1;
    }
};