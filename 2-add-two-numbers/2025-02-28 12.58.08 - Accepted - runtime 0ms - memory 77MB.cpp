/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 typedef ListNode Node;
class Solution {
public:
    Node* addTwoNumbers(Node* head1, Node* head2) {
         Node* temp1= head1;
    Node* temp2 = head2;
    Node* result= new Node(0);
    Node* curr= result;
    int carry=0;
    while( temp1 != nullptr || temp2 != nullptr){
        int sum = carry;
        if( temp1) sum = sum + temp1->val;
        if( temp2) sum = sum + temp2->val;
        carry = sum/10;

        Node* newNode = new Node( sum%10 );
        curr->next=newNode;
        curr= newNode;

        if(temp1) temp1=temp1->next;
        if(temp2) temp2= temp2->next;


    }
    if(carry){
        Node* newNode= new Node(carry);
        curr->next= newNode;
    }
    return result->next;
        
    }
};