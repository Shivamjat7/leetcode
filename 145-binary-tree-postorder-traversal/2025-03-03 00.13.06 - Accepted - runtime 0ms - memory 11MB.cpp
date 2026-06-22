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
    vector<int> postorderTraversal(TreeNode* root) {
             vector<int> nums;
        postOrder(root,nums);
        return nums;
        
    }
      void postOrder(TreeNode* node , vector<int> & arr){
        if(node == nullptr) return ;
        postOrder(node->left,arr);
        postOrder(node->right,arr);
        arr.push_back(node->val);

    }   
    
};