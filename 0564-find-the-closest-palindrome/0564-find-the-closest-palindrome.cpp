class Solution {
public:
    long long convert(long long num){
        string s = to_string(num);
        int  n = s.length();
        int l = (n-1)/2, r = n/2;
        while(l >= 0) s[r++] = s[l--];
        return stoll(s);
    }

    //maximization
    long long prevPalindrome (long long num) {
        long long l = 0, r = num-1;
        long long ans = -1e18;
        while(l <= r){
            long long mid = l + (r-l)/2;
            long long palin = convert(mid);
            if(palin < num){
                ans = palin;
                l = mid+1;
            }else{
                r = mid-1;
            }
        } 
        return ans;
    }
    //minimization
    long long nextPalindrome (long long num) {
        long long l = num+1, r = 1e18;
        long long ans = -1e18;
        while(l <= r){
            long long mid = l + (r-l)/2;
            long long palin = convert(mid);
            if(palin > num){
                ans = palin;
                r = mid-1;
            }else{
                l = mid+1;
            }
        } 
        return ans;
    }

    string nearestPalindromic(string n) {
        long long num = stoll(n), a = prevPalindrome(num), b = nextPalindrome(num);
        if(abs(num - a) <= abs(num - b)) return to_string(a);
        return to_string(b);
    }
};