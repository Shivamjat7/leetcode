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
    vector<TreeNode*> forest;
    unordered_set<int> del;
    TreeNode* dfs(TreeNode* root){
        if(!root)return nullptr;
        root->left= dfs(root->left);
        root->right= dfs(root->right);

        if(del.count(root->val)){
            if(root->left)forest.push_back(root->left);
            if(root->right)forest.push_back(root->right);
            root= nullptr;
        }
        return root;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        del = unordered_set<int>(to_delete.begin(),to_delete.end());
        root = dfs(root);
        if(root)forest.push_back(root);
        return forest;
    }
};