class Solution {
public:
    vector<long long> memo;
    long long foo(int i, vector<vector<int>>& questions) {
        if(i > questions.size()-1) return 0;
        if(memo[i] != -1) return memo[i];
        return memo[i] = max(
            questions[i][0] + foo(i+1 + questions[i][1], questions),
            foo(i+1, questions)
        );
    }
    long long mostPoints(vector<vector<int>>& questions) {
        memo = vector<long long>(questions.size()+1, -1);
        return foo(0, questions);
    }
};