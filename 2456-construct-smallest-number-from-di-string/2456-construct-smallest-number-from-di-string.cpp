class Solution {
public:
    string ans = "";
    vector<bool> used;
    bool dfs (int i, string pattern) {
        if(i == pattern.size()+1) return true;

        for(int num=1; num<=9; num++){
            if (i==0 || 
                !used[num] && (
                    (pattern[i-1] == 'I' && num > ans[i-1] - '0') ||
                    (pattern[i-1] == 'D' && num < ans[i-1] - '0')
                    )
                )
            {
                ans[i] = num + '0';
                used[num] = true;
                if(dfs(i+1, pattern)) return true;
                ans[i] = '0';
                used[num] = false;
            }   
        }
        return false;
    }

    string smallestNumber(string pattern) {
        ans = string(pattern.size()+1, '0');
        used = vector<bool>(10, false);
        return dfs(0, pattern) ? ans : "-1";
    }
};