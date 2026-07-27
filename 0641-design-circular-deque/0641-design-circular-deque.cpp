class MyCircularDeque {
private:
struct Node{
    int val;
    Node* next;
    Node* prev;
    Node(int v){
        val =v;
        next =prev = nullptr;
    }
};
public:
    int cap;
    Node* head =nullptr;
    Node* tail = nullptr;
    int len =0;
    MyCircularDeque(int k) {
        cap=k;
    }
    
    bool insertFront(int value) {
        if(isFull())return false;
        Node* newNode = new Node(value);
        if(!head){
            head = tail =newNode;
            len++;
            return true;
        }
        head->prev = newNode;
        newNode->next =head;
        head = newNode;
        len++;
        return true;
    }
    
    bool insertLast(int value) {
         if(isFull())return false;
        Node* newNode = new Node(value);
        if(!tail){
            head = tail =newNode;
            len++;
            return true;
        }
        newNode->prev=tail;
        tail->next=newNode;
        tail = newNode;
        len++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty())return false;
        if(head==tail){
            head=tail = nullptr;
            len--;
            return true;
        }
        Node* temp =head;
        head=head->next;
        delete temp;
        len--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty())return false;
        if(head==tail){
            head =tail =nullptr;
            len--;
            return true;
        }
        Node* temp = tail ;
        tail = tail->prev;
        delete temp;
        len--;
        return true;
    }
    
    int getFront() {
        return isEmpty()?-1:head->val;
        
    }
    
    int getRear() {
        return isEmpty()?-1:tail->val;
    }
    
    bool isEmpty() {
        return len==0;
    }
    
    bool isFull() {
        return len==cap;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */