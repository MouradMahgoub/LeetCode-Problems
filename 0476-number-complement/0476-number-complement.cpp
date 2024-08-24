class Solution {
public:
    int findComplement(int num) {
        for(int i=0; i<=33; i++)
            if((pow(2, i)) > num) return (pow(2, i)) - num - 1;
        return -1;
    }
};