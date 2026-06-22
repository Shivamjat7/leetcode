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
    pair<int,int> postOrder(TreeNode* root, int &ans){
        if(!root)return {0,0};
        auto[left,cnt1] = postOrder(root->left,ans);
        auto[right,cnt2] = postOrder(root->right,ans);
        int sum = left+right+root->val;
        int cnt = cnt1+cnt2+1;
        if(cnt &&  root->val==sum/cnt){
            ans++;
        }
        return {sum,cnt};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int ans =0;
        postOrder(root,ans);
        return ans;
    }
};