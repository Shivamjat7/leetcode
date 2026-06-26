/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* clone, Node* original ,unordered_map<Node* ,Node*>&mp){
        clone->val=original->val;
        mp[original]=clone;
        for(Node* neigh:original->neighbors){
            if(mp.find(neigh)==mp.end()){
                Node* newNode = new Node();
                mp[neigh]=newNode;
                dfs(newNode,neigh,mp);
            }
            clone->neighbors.push_back(mp[neigh]);

        }
        
    }
    Node* cloneGraph(Node* node) {
        if(!node)return nullptr;
        Node* newNode = new Node();
        unordered_map<Node*,Node*>mp;
        dfs(newNode,node,mp);
        return newNode;
    }
};