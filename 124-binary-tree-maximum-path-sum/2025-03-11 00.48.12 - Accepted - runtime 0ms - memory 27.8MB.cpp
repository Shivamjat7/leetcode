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
    int MaxSum=INT_MIN;
   
    int maxSum(TreeNode* root){
        if(! root) return 0;
        int leftSum = max(0,maxSum(root->left));
        int rightSum =max(0 ,maxSum(root->right));
        MaxSum = max(MaxSum ,leftSum + rightSum + root->val);
        return root->val + max(leftSum,rightSum);
    }
     int maxPathSum(TreeNode* root) {
        MaxSum = INT_MIN;
        maxSum(root);
        return MaxSum;

        
    }
};