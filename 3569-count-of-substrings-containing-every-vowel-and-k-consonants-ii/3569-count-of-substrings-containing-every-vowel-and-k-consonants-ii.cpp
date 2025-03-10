class Solution {
public:
    bool isVowel (char c) {
        return c == 'a' || c == 'e' || c == 'o' || c == 'u' || c == 'i'; 
    }
    long long countAtLeastK (string word, int k) {
        int n = word.size();
        unordered_map<char, int> vowel;
        int consonants = 0;
        int l=0, r=0;
        long long cnt=0;
        for(int r=0; r<n; r++){
            if(isVowel(word[r])) vowel[word[r]]++;
            else consonants++;
            while(vowel.size() == 5 && consonants >= k) {
                cnt += n - r;
                if(isVowel(word[l])) vowel[word[l]]--;
                else consonants--;
                if(vowel[word[l]] == 0) vowel.erase(word[l]);
                l++;
            }
        }
        return cnt;
    }

    long long countOfSubstrings(string word, int k) {
        return countAtLeastK(word, k) - countAtLeastK(word, k+1);
    }
};