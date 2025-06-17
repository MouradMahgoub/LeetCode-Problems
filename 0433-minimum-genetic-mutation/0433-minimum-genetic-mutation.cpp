class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<string> q;
        unordered_map<string, int> visited;
        q.push(startGene);
        visited[startGene] = 1;
        int steps = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                string curr = q.front(); q.pop();
                if(curr == endGene) return steps;
                for(string s : bank){
                    if(visited[s] == 0 && getDiff(curr, s) == 1){
                        q.push(s);
                        visited[s] = 1;
                    }
                }
            }
            steps++;
        }
        return -1;
    }

    int getDiff (string s1, string s2) {
        int cnt = 0;
        for(int i=0; i<min(s1.size(), s2.size()); i++)
            cnt += (s1[i] != s2[i]);
        return cnt;
    }
};