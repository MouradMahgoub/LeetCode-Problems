class Solution {
public:
    string fractionAddition(string exp) {
        int ansN=0, ansD=1;
        if(exp[0] != '-') exp = '+' + exp;
        int indx = 0, sign = 1;
        while(indx < exp.size()){
            int tempN = 0, tempD = 0;
            sign = (exp[indx] == '+' ? 1 : -1);
            indx++;
            while(exp[indx] != '/') tempN = tempN*10 + (exp[indx++] - '0');
            indx++;
            while(indx < exp.size() && exp[indx] != '+' && exp[indx] != '-') tempD = tempD*10 + (exp[indx++] - '0');
            ansN = (ansN*tempD + sign*tempN*ansD)/__gcd(ansD, tempD);
            ansD = (ansD*tempD)/__gcd(ansD, tempD);
        }
        return to_string(ansN/abs(__gcd(ansN, ansD))) + "/" + to_string(ansD/abs(__gcd(ansN, ansD)));
    }
};