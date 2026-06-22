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
    bool isUnivalTree(TreeNode* root) {
        if(!root)return true;
        bool check=true;
        if(root->left) check = root->val ==root->left->val;
        if(root->right) check = check && root->val ==root->right->val;
        return check && isUnivalTree(root->left)&& isUnivalTree(root->right);

    }
};