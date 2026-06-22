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
    int diameterOfBinaryTree(TreeNode* root) {
        int dia=0;
        diameter(root,dia);
        return dia;
        
        
    }
    int diameter(TreeNode* root , int & dia){
        if(!root) return -1;
        int lH = diameter(root->left,dia);
        int rH = diameter(root->right,dia);
        dia = max( dia, lH + rH +2);
        return  1+ max( lH,rH);
    }
};