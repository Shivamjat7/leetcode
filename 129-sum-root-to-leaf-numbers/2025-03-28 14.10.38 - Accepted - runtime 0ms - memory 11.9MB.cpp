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
    int sumNumbers(TreeNode* root) {
        int sum =0;
        helper(root,sum ,0);
        return sum;
        
    }
    void helper(TreeNode* root, int &sum,int num){
        if(!root) return ;
        num = num*10 + root->val;
        if(!root->left && !root->right) {
            sum += num;
            return;
        }
        helper(root->left,sum,num);
        helper(root->right,sum,num);
    }
};