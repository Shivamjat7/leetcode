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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent;

    
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* target =nullptr;

        while (!q.empty()) {

            TreeNode* node = q.front();
            if (node->val==start)target =node;
            q.pop();

            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }

            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }

    
        unordered_set<TreeNode*> vis;
        q.push(target);
        vis.insert(target);

        int dist = 0;

        while (!q.empty()) {
            int sz = q.size();

            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left && !vis.count(node->left)) {
                    vis.insert(node->left);
                    q.push(node->left);
                }

                if (node->right && !vis.count(node->right)) {
                    vis.insert(node->right);
                    q.push(node->right);
                }

                if (parent.count(node) && !vis.count(parent[node])) {
                    vis.insert(parent[node]);
                    q.push(parent[node]);
                }
            }

            dist++;
        }
        return dist-1;
    }
};