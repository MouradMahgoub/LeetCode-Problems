class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for(int i : arr1) mp[i]++;
        for(int i=0; i<arr2.size(); i++){
            while(mp[arr2[i]]){
                ans.push_back(arr2[i]);
                mp[arr2[i]]--;
            }
        }
        vector<int> temp;
        for(int i=0; i<arr1.size(); i++) {
            if(mp[arr1[i]]){
                temp.push_back(arr1[i]);
                mp[arr1[i]]--; 
            }
        }
        sort(temp.begin(), temp.end());
        for(int num : temp) ans.push_back(num);
        return ans;
    }
};