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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root) return root;
        if(depth==1){
            TreeNode* newNode= new TreeNode(val);
            newNode->left = root;
            return newNode;
        }
        else if(depth==2){
            TreeNode* l = new TreeNode(val);
            TreeNode* r = new TreeNode(val);
            l->left = root->left;
            r->right= root->right;
            root->left=l;
            root->right=r;
        }
        if(depth>2){
        addOneRow(root->left,val,depth-1);
        addOneRow(root->right,val,depth-1);}
        return root;
    }
};