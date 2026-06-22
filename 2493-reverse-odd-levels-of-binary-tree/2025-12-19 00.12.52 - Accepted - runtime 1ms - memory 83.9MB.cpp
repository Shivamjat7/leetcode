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
    TreeNode* reverseOddLevels(TreeNode* root) {
         queue<TreeNode*> q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            int levelSize = q.size();
             vector<TreeNode*> temp;
            for(int i =0;i<levelSize;i++){
                TreeNode* curr = q.front();
                q.pop();
                temp.push_back(curr);
                if(curr->left){
                    q.push(curr->left);
                    q.push(curr->right);
                }
            }
            if(level % 2 !=0){

            int l =0, r = temp.size()-1;
            while(l<r){
                swap(temp[l]->val,temp[r]->val);
                l++;
                r--;
            }
            

                
            }
            level++;
        }
        return root;
        
    }
};