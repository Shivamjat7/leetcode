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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)return ans;
        map<int,map<int,multiset<int>>> mpp;
        queue<pair<TreeNode* ,pair<int,int>>> q;
        q.push( {root,{0,0}});
        while(!q.empty()){
            auto it= q.front();
            q.pop();
            TreeNode* curr=it.first;
            int col = it.second.first;
            int row= it.second.second;
            mpp[col][row].insert(curr->val);
            if(curr->left) q.push( {curr->left,{col-1,row+1}});
            if(curr->right) q.push( {curr->right,{col+1,row+1}});

        }
        for(auto &colPair:mpp){
            vector<int> colVal;
            for(auto &rowPair:colPair.second){
                for(auto v:rowPair.second) colVal.push_back(v);
            }
            ans.push_back(colVal);

        }
return ans;
        
    }
};