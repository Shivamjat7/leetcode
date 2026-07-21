class AllOne {
    struct Node {
        int count;
        unordered_set<string> keys;
        Node* prev;
        Node* next;
        Node(int c) : count(c), prev(NULL), next(NULL) {}
    };

    unordered_map<string, Node*> mp;
    Node* head;
    Node* tail;

public:
    AllOne() {
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
    }

    void addNodeAfter(Node* prev, Node* newNode) {
        newNode->next = prev->next;
        newNode->prev = prev;
        prev->next->prev = newNode;
        prev->next = newNode;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }

    void inc(string key) {
        if (!mp.count(key)) {
            Node* node;
            if (head->next->count == 1) {
                node = head->next;
            } else {
                node = new Node(1);
                addNodeAfter(head, node);
            }
            node->keys.insert(key);
            mp[key] = node;
        } else {
            Node* cur = mp[key];
            Node* nextNode;

            if (cur->next->count == cur->count + 1) {
                nextNode = cur->next;
            } else {
                nextNode = new Node(cur->count + 1);
                addNodeAfter(cur, nextNode);
            }

            nextNode->keys.insert(key);
            mp[key] = nextNode;

            cur->keys.erase(key);
            if (cur->keys.empty()) removeNode(cur);
        }
    }

    void dec(string key) {
        Node* cur = mp[key];

        if (cur->count == 1) {
            mp.erase(key);
        } else {
            Node* prevNode;

            if (cur->prev->count == cur->count - 1) {
                prevNode = cur->prev;
            } else {
                prevNode = new Node(cur->count - 1);
                addNodeAfter(cur->prev, prevNode);
            }

            prevNode->keys.insert(key);
            mp[key] = prevNode;
        }

        cur->keys.erase(key);
        if (cur->keys.empty()) removeNode(cur);
    }

    string getMaxKey() {
        if (tail->prev == head) return "";
        return *(tail->prev->keys.begin());
    }

    string getMinKey() {
        if (head->next == tail) return "";
        return *(head->next->keys.begin());
    }
};