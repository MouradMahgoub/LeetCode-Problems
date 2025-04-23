class Solution {
public:
    string reverseVowels(string s) {
        int l=0, r=s.size()-1;
        string vowels = "aeiouAEIOU";
        while(l < r){
            while(l < r && vowels.find(s[l]) == -1) l++;
            while(l < r && vowels.find(s[r]) == -1) r--;
            swap(s[l], s[r]);
            l++;
            r--;
        }
        return s;
    }
};
        // int i=0, j=s.size()-1;
        // while(i < j){
        //     i = s.find_first_of("aeiouAEIOU", i);
        //     j = s.find_last_of("aeiouAEIOU", j);
        //     if(i < j) swap(s[i++], s[j--]);
        // }
        // return s;