class Solution {
public:
    vector<vector<int>> memo;

    int minDistance(string s1, string s2) {
        memo = vector<vector<int>>(s1.size(), vector<int>(s2.size(), -1));
        return foo(0, 0, s1, s2);
    }

    int foo (int i, int j, string s1, string s2) {
        if(j == s2.size()) return s1.size() - i;
        if(i == s1.size()) return s2.size() - j;

        if(memo[i][j] != -1) return memo[i][j];

        if(s1[i] == s2[j])
            return memo[i][j] = foo(i+1, j+1, s1, s2);
        
        return memo[i][j] = 1 + min(
                    foo(i, j+1, s1, s2),
                min(foo(i+1, j, s1, s2), 
                    foo(i+1, j+1, s1, s2))
                );
    }
};