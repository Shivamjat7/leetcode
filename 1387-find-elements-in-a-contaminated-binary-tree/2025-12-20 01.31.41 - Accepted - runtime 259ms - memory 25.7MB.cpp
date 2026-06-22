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
class FindElements {
    TreeNode* recover(TreeNode* root,int x){
        if(!root)return root;
        root->val=x;
        root->left =recover(root->left,2*x+1);
       root->right= recover(root->right,2*x+2);
       return root;
    }
    bool f(TreeNode* root,int target){
        if(!root) return false;
        if(root->val==target) return true;
        if(f(root->left,target))return true;
        return f(root->right,target);
    }
public:
    TreeNode* Root;
    FindElements(TreeNode* root) {
       Root= recover(root,0);
    }
    
    bool find(int target) {
        return f(Root,target);

    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */