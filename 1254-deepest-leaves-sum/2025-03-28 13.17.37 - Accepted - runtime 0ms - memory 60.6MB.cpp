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
    int deepestLeavesSum(TreeNode* root) {
        int sum =0;
        int H=0;
        helper(root,0,sum,H);
        return sum;

        
    }
    void helper(TreeNode* root,int h, int &sum ,int & H){
        if(!root) return ;
        if(!root->left && !root->right){
            if(h>H){
                sum = root->val;
                H=h;
            }else if( h==H) {
                sum += root->val;
            }
        }
        helper(root->left,h+1,sum,H);
        helper(root->right,h+1,sum,H);
    }
};