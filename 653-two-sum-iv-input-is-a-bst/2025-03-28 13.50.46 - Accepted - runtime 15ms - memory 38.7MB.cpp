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
    map<int,int>mpp;
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        int rem = k -root->val;
        if(mpp.find(rem)!=mpp.end()) return true;
        mpp[root->val]++;
        return findTarget(root->left,k) || findTarget(root->right,k);


        
    }

};