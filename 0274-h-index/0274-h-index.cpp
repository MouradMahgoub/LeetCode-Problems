class Solution {
public:
    int hIndex(vector<int>& v) {
        int h = 0;
        sort(v.begin(), v.end(), greater<int>());
        for(int i=0; i<v.size(); i++){
            if(h < v[i]) h++;
            else break;
        }
        return h;
    }
};