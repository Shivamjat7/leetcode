class MyCircularQueue {
public:
    int len =0;
    struct Node{
        int val;
        Node* next;
        Node(int v){
            val = v;
            next = nullptr;
        
        }
    };
    Node* head=nullptr;
    Node* tail=nullptr;
    int cap=0;
    MyCircularQueue(int k) {
        cap =k;
    }
    
    bool enQueue(int value) {
        if(len==cap)return false;
        Node* newNode = new Node(value);
        if(!head){
           tail= head = newNode;
           len++;
           return true;
        }
        tail->next = newNode;
        tail =newNode;
        len++;
        return true;
    }
    
    bool deQueue() {
        if(len==0)return false;

        Node* temp = head;
        head=head->next;
        len--;
        delete temp;
        return true;
    }
    
    int Front() {
        if(len==0)return -1;
        return head->val;
    }
    
    int Rear() {
        if(len==0)return -1;
        return tail->val;
    }
    
    bool isEmpty() {
        return len ==0;
    }
    
    bool isFull() {
        return len ==cap;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */