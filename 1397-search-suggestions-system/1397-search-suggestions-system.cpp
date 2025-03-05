class Solution {
private:
    struct TrieNode{
        map<char, TrieNode*> children;
        bool endOfWord = false;
    };

    void insert (TrieNode* root, string word) {
        TrieNode* curr = root;
        for(char c : word){
            if(!curr->children[c])
                curr->children[c] = new TrieNode();
            curr = curr->children[c];
        }
        curr->endOfWord = true; 
    }

    vector<string> getWordsWithPrefix(TrieNode* root, string prefix) {
        vector<string> res;
        TrieNode* curr = root;
        for(char c : prefix){
            if(!curr->children[c])
                return res;
            curr = curr->children[c];
        }
        dfs(prefix, curr, res);
        return res;
    }

    void dfs (string str, TrieNode* root, vector<string>& res) {
        if(!root || res.size() == 3) return;
        if(root->endOfWord) res.push_back(str);
        for(auto [c, node] : root->children)
            dfs(str+c, node, res);
    }

public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        TrieNode* root = new TrieNode();
        for(string s : products)
            insert(root, s);
        string prefix = "";
        for(char c : searchWord){
            prefix += c;
            ans.push_back(getWordsWithPrefix(root, prefix));
        }
        return ans;
    }
};