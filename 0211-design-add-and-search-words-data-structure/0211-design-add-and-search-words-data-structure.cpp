class WordDictionary {
private:
    struct Node {
        unordered_map<char, Node*> children;
        bool endOfWord = false;
    };
public:
    Node* root;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* curr = root;
        for(char c : word){
            if(!curr->children[c])
                curr->children[c] = new Node();
            curr = curr->children[c];
        } 
        curr->endOfWord = true;
    }
    
    bool search(string word) {
       return search(0, root, word);
    }

    bool search(int indx, Node* curr, string word) {
        for(int i=indx; i<word.size(); i++){
            char c = word[i];
            if(c == '.') {
                for(auto [c, node] : curr->children)
                    if(node && search(i+1, node, word)) 
                        return true;
                return false;
            }
            if(!curr->children[c])
                return false;
            curr = curr->children[c];
        }
        return curr && curr->endOfWord;
    }

};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */