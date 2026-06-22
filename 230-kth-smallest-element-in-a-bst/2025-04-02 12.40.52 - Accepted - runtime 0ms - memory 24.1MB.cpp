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
public:
    
int cnt =0;
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        int ans =0;
        helper( root,k,ans);
        return ans;

        
        
    }
    void helper( TreeNode* root, int k,int & ans){
        if(!root) return ;
        helper(root->left,k,ans);
        cnt++;
        if(cnt == k ){
            ans = root->val;
            return ;
        }
        helper( root->right,k,ans);
    }
};