class Node {
public:
    int key, value;
    Node *prev, *next;

    Node(int k, int v) {
        key = k;
        value = v;
        prev = next = nullptr;
    }
};
class LRUCache {
private:
    int cap;
    unordered_map<int,Node*>mp;
    Node* tail=nullptr, *head = nullptr;

    void remove(Node* node){
         node->prev->next = node->next;
         node->next->prev = node->prev;
    }
    void insert(Node* node){
        node->next =head->next;
        node->prev =head;
        head->next->prev =node;
        head->next=node;

    }
public:
    LRUCache(int capacity) {
        cap =capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next=tail;
        tail->prev =head;
    }
    
    int get(int key) {
        if(!mp.count(key))return -1;
        Node* node = mp[key];
        remove(node);
        insert(node);
        return node->value;

        
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            Node* node = mp[key];
            remove(node);
            insert(node);
            node->value=value;
            return;
        }
        if(mp.size()==cap){
            Node* lru =tail->prev;
            remove(lru);
            mp.erase(lru->key);
            delete lru;

        }
        Node* node = new Node(key,value);
        mp[key]=node;
        insert(node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */