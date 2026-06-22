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
private:
     void inorder(TreeNode* root, TreeNode* &prev,int& diff){
        if(!root) return;
        inorder(root->left,prev,diff);
        if(prev)
        diff = min(diff,abs(root->val-prev->val));
        prev=root;
        inorder(root->right,prev,diff);
     }
public:
    int getMinimumDifference(TreeNode* root) {
        int diff= INT_MAX;
        TreeNode* prev = nullptr;
        inorder(root,prev,diff);
        return diff;
    }
};