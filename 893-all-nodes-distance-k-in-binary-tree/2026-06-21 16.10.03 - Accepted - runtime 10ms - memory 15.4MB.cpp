/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* ,TreeNode*>parent;
        queue<TreeNode*>q;
        q.push(root);
        while (!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                parent[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right]=node;
                q.push(node->right);
            }
        }
        unordered_set<TreeNode*>vis;
        int dist =0;
        q.push(target);
        vis.insert(target);
        vector<int> ans;
        while(!q.empty()){
            int sz = q.size();

            if(dist ==k){
                for(int i =0;i<sz;i++){
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                return ans;
            }

            for(int i =0;i<sz;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !vis.count(node->left)){
                    q.push(node->left);
                    vis.insert(node->left);
                }
                if(node->right && !vis.count(node->right)){
                    q.push(node->right);
                    vis.insert(node->right);
                }
                if(parent.count(node) && !vis.count(parent[node])){
                    q.push(parent[node]);
                    vis.insert(parent[node]);
                }
                
            }
            dist++;
        }
        return ans;
    }
};