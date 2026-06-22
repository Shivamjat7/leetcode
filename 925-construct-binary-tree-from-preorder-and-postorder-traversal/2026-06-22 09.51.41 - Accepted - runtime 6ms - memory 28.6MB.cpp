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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        map<int,int>mp;
        for(int i =0;i<postorder.size();i++)mp[postorder[i]]=i;
        return built(preorder,0,preorder.size()-1,postorder,0,postorder.size()-1,mp);
    }
    TreeNode* built (vector<int>& preorder,int preS,int preE, vector<int>& postorder,int posS,int posE,map<int,int>&mp){
        if(preS>preE||posS>posE)return nullptr;
        TreeNode* root = new TreeNode(preorder[preS]);
        if(preS==preE)return root;
        int idx = mp[preorder[preS+1]];
        int leftSize = idx -posS+1;
        root->left = built(preorder,preS+1,preS+leftSize,postorder,posS,posS+leftSize-1,mp);
        root->right = built(preorder,preS+leftSize+1,preE,postorder,posS+leftSize,posE-1,mp);
        return root;


    }
};