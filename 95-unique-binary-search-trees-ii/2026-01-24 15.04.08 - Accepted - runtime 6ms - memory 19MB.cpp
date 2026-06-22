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
    vector<TreeNode*> build(int low ,int high){
        if(low>high)return{ nullptr};
        vector<TreeNode*>res;
    for(int rootVal=low;rootVal<=high;rootVal++){
        vector<TreeNode*>leftSubtree = build( low,rootVal-1);
        vector<TreeNode*>rightSubtree = build(rootVal+1,high);
        for(auto left :leftSubtree){
            for(auto right:rightSubtree){
                TreeNode* root = new TreeNode(rootVal);
                root->left =left;
                root->right = right;
                res.push_back(root);
            }
        }
        }
        
      return res; 
    }
    vector<TreeNode*> generateTrees(int n) {
       
        return build (1,n);
    }
};