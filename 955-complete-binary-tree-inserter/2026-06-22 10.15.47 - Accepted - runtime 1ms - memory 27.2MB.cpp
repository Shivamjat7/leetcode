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
class CBTInserter {
public:
    queue<TreeNode*>q;
    TreeNode* root;
    
    CBTInserter(TreeNode* root) {
        this->root = root;
        queue<TreeNode*>bfs;
        bfs.push(root);
        while(!bfs.empty()){
            TreeNode* node = bfs.front();bfs.pop();
            if(!(node->left && node->right)) q.push(node);
            if(node->left)bfs.push(node->left);
            if(node->right)bfs.push(node->right);
        }
    }
    
    int insert(int val) {
            TreeNode* newNode = new TreeNode(val);
            TreeNode* node =q.front();
            if(node->left){
                node->right=newNode;
                q.pop();
            }
            else node->left=newNode;
            q.push(newNode);
            return node->val;

    }
    
    TreeNode* get_root() {
        return this->root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */