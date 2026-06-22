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
    bool dfs(TreeNode* root,TreeNode* subRoot){
        if(!root && !subRoot)return true;
        if(!root || !subRoot||root->val!=subRoot->val)return false;
        return dfs(root->left,subRoot->left)&& dfs(root->right,subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot)return true;
        if(!root || !subRoot )return false;
        bool check =false;
        if(root->val == subRoot->val)check= dfs(root,subRoot);
        return check|| isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
    }
};