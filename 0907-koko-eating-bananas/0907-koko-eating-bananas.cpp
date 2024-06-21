class Solution {
public:
    bool good(vector<int>& piles, int k, int h) {
        int sum = 0;
        for(int& pile : piles) sum += ceil(1.0*pile/k); 
        return sum <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1, r = *max_element(piles.begin(), piles.end());
        while(l < r){
            int mid = l + (r-l)/2;
            if(good(piles, mid, h)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return l;
    }
};