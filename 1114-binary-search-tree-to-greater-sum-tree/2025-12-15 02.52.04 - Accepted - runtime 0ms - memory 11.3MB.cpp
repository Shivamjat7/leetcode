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
    void inorder(TreeNode*root,int & total){
        if(!root)return;
        inorder(root->left,total);
        total+=root->val;
        inorder(root->right,total);

    }
    void gst(TreeNode* root,int & prevSum ,int total){
        if(!root)return;
        gst(root->left,prevSum,total);
        prevSum += root->val;
        root->val = root->val+ total-prevSum;
        gst(root->right,prevSum,total);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        int total =0;
        int prev=0;
        inorder(root,total);
        gst(root,prev,total);
        return root;
    }
};