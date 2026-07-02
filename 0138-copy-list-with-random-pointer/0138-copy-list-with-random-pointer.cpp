/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copy(Node* original,unordered_map<Node*,Node*>&mp){
        if(!original)return nullptr;
        if(mp.contains(original)) return mp[original];
        Node* newNode = new Node(original->val);
        mp[original]=newNode;
        newNode->next =copy(original->next,mp);
        newNode->random=copy(original->random,mp);
        return newNode;
    }
    Node* copyRandomList(Node* head) {
        unordered_map<Node* ,Node*>mp;
        return copy(head,mp);
        
        
    }
};