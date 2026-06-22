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

    
    string serialize(TreeNode* root) {
        if(!root)return "";
       string s= to_string(root->val);
        if(root->left){
            s+='(';
            s+=serialize(root->left);
            s+=')';
        }
        if(!root->left && root->right){
            s+="()";
        }
        if(root->right){
            s+='(';
            s+=serialize(root->right);
            s+=')';
        }
        return s;
    }
    TreeNode* build(string s,int &i){
        if(i>=s.size())return nullptr;
        if(s[i]==')') return nullptr;
        int sign =1;
        if(s[i]=='-'){
            sign =-1;
            i++;
        }
        int num =0;
        while(i<s.size() && isdigit(s[i])){
            num=num*10 + int(s[i]-'0');
            i++;
        }
        TreeNode* root = new TreeNode(num*sign);
        if(i<s.size() && s[i]=='('){
            i++;
            root->left = build(s,i);
            i++;
        }
        if(i<s.size() && s[i]=='('){
            i++;
            root->right = build(s,i);
            i++;
        }
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        int i=0;
        return build(s,i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));