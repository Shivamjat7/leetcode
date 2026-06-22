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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*>q;
        int level = 1;
        int levelSize=0;
        q.push(root);

        while(!q.empty()){
             levelSize = q.size();
             vector<int> arr;
             for(int i =0;i<levelSize;i++){
                TreeNode* curr = q.front();
                q.pop();
                arr.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);

             }
             if(level%2 !=0) res.push_back(arr);
             else {
                int left =0;
                int right=arr.size()-1;
                while(left<right){
                    int temp = arr[right];
                    arr[right]= arr[left];
                    arr[left]=temp;
                    left++;
                    right--;
                }
                res.push_back(arr);
             }
             level++;

        }
        return res;
    }
};