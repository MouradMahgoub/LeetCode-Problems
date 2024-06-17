class Solution {
public:
    void countingSort(vector<int> & v) {
        unordered_map<int, int> mp;
        for(int& i : v) mp[i]++;
        int mn = *min_element(v.begin(), v.end());
        int mx = *max_element(v.begin(), v.end());
        int index = 0;
        for(int i=mn; i<=mx; i++)
            while(mp[i]-- > 0) v[index++] = i;
    }

    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        countingSort(seats);
        countingSort(students);
        int ans = 0;
        for(int i=0; i<seats.size(); i++)
            ans += abs(seats[i] - students[i]);
        return ans;
    }
};