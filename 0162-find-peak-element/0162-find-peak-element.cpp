class Solution {
public:
    int findPeakElement(vector<int>& v) {
        if(v.size() == 1 || v[0] > v[1]) return 0;
        if(v[v.size()-1] > v[v.size()-2]) return v.size()-1;
        int l=1, r=v.size()-2;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(v[mid] > v[mid-1] && v[mid] > v[mid+1]) return mid; 
            else if(v[mid] < v[mid+1]) l = mid+1;
            else r = mid;
        }
        return -1; 
    }
};