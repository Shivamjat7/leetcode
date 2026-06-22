class MinStack {
    private:
    
    struct Node{
        int val;
        int currentMin;
        Node* next;
        Node(int data,int min){
            val = data;
            currentMin =min;
            next = nullptr;
        }
    };
    Node* topNode = nullptr;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(!topNode){
            topNode = new Node(val,val);
        return;
        }
        int currentMin = min(val ,topNode->currentMin);
        Node* newNode = new Node(val,currentMin);
        newNode->next = topNode;
        topNode=newNode;
        
    }
    
    void pop() {
        if(!topNode) return;
        topNode = topNode->next;
    }
    
    int top() {
        if(topNode) return topNode->val;
        return -1;
        
    }
    
    int getMin() {
      return topNode->currentMin;  
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */