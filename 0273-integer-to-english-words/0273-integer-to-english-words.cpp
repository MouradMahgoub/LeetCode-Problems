class Solution {
public:
    vector<string> v1 = {"", "Thousand", "Million", "Billion"};
    vector<string> v2 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> v3 = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> v4 = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

    string foo(int num) {
        string ans = "";
        if(num >= 100){
            ans += " " + v2[num/100] + " Hundred"; 
        }
        num %= 100;
        if(num/10 == 1){
            ans += " " + v4[num%10];
            return ans;
        }
        if(num >= 20){
            ans += " " + v3[num/10]; 
        }
        num %= 10;
        if(num >= 1){
            ans += " " + v2[num]; 
        }
        return ans;
    }

    string numberToWords(int num) {
        if(num == 0) return "Zero";
        string ans = "";
        int i=0;
        while(num){
            if(num%1000)
                ans = foo(num%1000) + " " + v1[i]  +  ans;
            num /= 1000;
            i++;
        }
        while(ans[0] == ' ') ans.erase(ans.begin());
        while(ans[ans.size()-1] == ' ') ans.pop_back();
        return ans;
    }
};