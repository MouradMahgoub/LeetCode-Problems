/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> v;
        string s = "";
        for(auto c : data){
            if(c == ','){
                v.push_back(stoi(s));
                s = "";
                continue;
            }
            s += c;
        }
        return get_deserialize(v, 0, v.size()-1);
    }

    TreeNode* get_deserialize(vector<int>& v, int s, int e){
        if(s > e) return NULL;
        TreeNode* root = new TreeNode(v[s]);
        int leftLen = 0;
        for(int i=s+1; i<=e; i++){
            if(v[i] > v[s]) break;
            leftLen++;
        }
        root->left = get_deserialize(v, s+1, s+leftLen);
        root->right = get_deserialize(v, s+leftLen+1, e);
        return root;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;