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
    int height(TreeNode* root){
        if(!root)return 0;
        return 1+max(height(root->left),height(root->right));
    }
    TreeNode* lca(TreeNode* root, TreeNode* p,TreeNode* q){
        if(!root||root==p||root==q)return root;
        TreeNode* left = lca(root->left,p,q);
        TreeNode* right = lca(root->right,p,q);
        if(left && right) return root;
        return left?left:right;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int ht = height(root);
        queue<pair<TreeNode* ,int>>q;
        q.push({root,1});
        TreeNode* first=nullptr,*last=nullptr;
        while(!q.empty()){
            auto[curr,level] = q.front();
            q.pop();
            if(level ==ht){
                if(!first)first=curr;
                last =curr;
            }
            if(curr->left) q.push({curr->left,level+1});
            if(curr->right) q.push({curr->right,level+1});
        }
        return lca(root,first,last);
        
    }
};