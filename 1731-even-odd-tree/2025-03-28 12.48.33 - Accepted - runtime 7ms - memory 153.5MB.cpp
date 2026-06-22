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
    bool isEvenOddTree(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode* > q;
        q.push(root);
        int height=0;
        while(!q.empty()){
        
            int levelSize =  q.size();
            int prev =0;
            
            while(levelSize--){
                TreeNode* curr= q.front();
                q.pop();
                if(height %2 ==0){
                    if(curr->val%2 ==0 ||(prev && prev>=curr->val)) return false;
                    

                
                }else{
                    if(curr->val%2 !=0 || (prev && prev<=curr->val)) return false;
                }

                prev =curr->val;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            height++;
        }
        return true;
    }
};