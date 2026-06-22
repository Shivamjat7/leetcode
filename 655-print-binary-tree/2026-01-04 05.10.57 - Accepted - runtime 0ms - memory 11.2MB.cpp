/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int height (TreeNode* root){
        if(!root) return 0;
        return max(height(root->left),height(root->right))+1;
    }
    
    void f (TreeNode* root,int i,int j,int ht,vector<vector<string>>&ans){
        if(!root) return ;
        ans[i][j]= to_string(root->val);
        int c = pow(2,ht-i-2);
        f(root->left,i+1,j-c,ht,ans);
        f(root->right,i+1,j+c,ht,ans);
    }
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int ht = height(root);
        int m = ht;
        int n =pow(2,ht)-1;
        vector<vector<string>> ans (m,vector<string>(n,""));
        f(root,0,(n-1)/2,ht,ans);
        return ans;
    }
};