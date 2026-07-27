class MyLinkedList {
    struct Node{
        int val;
        Node* next ;
        Node(int val){
            this->val = val;
            next = nullptr;
        }
    };
public:
    Node* head = nullptr;
    Node* tail = nullptr;
    MyLinkedList() {
        
    }
    
    int get(int index) {
        int cnt =0;
        Node* temp = head;
        while(temp && cnt!=index){
            temp = temp->next;
            cnt++;
        }
        if(!temp)return -1;
        return temp->val;
    }
    
    void addAtHead(int val) {
        Node* node = new Node(val);
        if(!head){
            head = tail = node;
            return ;
        }
        node->next =head;
        head=node;
        
    }
    
    void addAtTail(int val) {
        Node* node=new Node(val);
        if(!tail){
            head = tail = node;
            return ;
        }
        tail->next =node;
        tail = node;
    }
    
    void addAtIndex(int index, int val) {
        if(index==0){
           addAtHead(val);
           return;
        }
        int cnt =0;
        Node* node = new Node(val);
        Node* temp = head;
        while(temp && cnt!=index-1){
            temp = temp->next;
            cnt++;
        }
        if(!temp)return;
        
        node->next =temp->next;
        temp->next = node;
        if(!node->next)tail =node;
        
    }
    
    void deleteAtIndex(int index) {
         int cnt =0;
        if(index==0){
            if(head==tail){
                head=tail =nullptr;
            }else{
                Node* temp = head;
                head = head->next;
                delete temp;
            }
            return;
        }
        Node* temp = head;
        while(temp && cnt!=index-1){
            temp = temp->next;
            cnt++;
        }
        if(!temp ||!temp->next)return;
        Node* del = temp->next;
        temp->next = del->next;
        if(del==tail)tail =temp;
        delete del;
        return;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */