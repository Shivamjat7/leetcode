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
    long long sum(TreeNode* root){
        if(!root)return 0;
        long long ls = sum(root->left);
        long long rs = sum (root->right);
        return root->val+ls+rs;
    }
    long long f(TreeNode* root, long long total,long long & product){
            if(!root)return 0;
        long long ls = f(root->left,total,product);
        long long rs = f (root->right,total,product);
        product = max({product, (total-ls)*ls,(total-rs)*rs});
        
        return root->val+ls+rs;
    }
    int maxProduct(TreeNode* root) {
        long long s= sum(root);
        long long product=0;
        long long MOD=1e9+7;
        f(root,s,product);
        return product%MOD;

    }
};