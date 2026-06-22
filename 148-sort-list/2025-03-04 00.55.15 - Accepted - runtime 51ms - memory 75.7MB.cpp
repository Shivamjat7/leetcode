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
    ListNode* sortList(ListNode* head) {
          if(!head || !head->next) return head;

            Node* mid = findMiddle(head);
            Node* left =head;
            Node* right=mid->next;
            mid->next = nullptr;

            left= sortList(left);
            right =sortList(right);
            return  merge(left,right);
        
    }
    Node* findMiddle(Node* head){
            if( !head || !head->next) return head;
            Node* fast=head->next;
            Node* slow=head;
            while(fast && fast->next){
                fast= fast->next->next;
                slow=slow->next;

            }
            return slow;
}
// merging two sorted linkedlist using iteration:

Node* merge(Node* left, Node* right){
        if(!left) return right;
        if(!right) return left;

        Node* merged = new Node(0);
        Node* temp = merged;

        while(left && right){
            if( left->val < right->val){
                temp->next =left;
                left=left->next;
            }else{
                temp->next=right;
                right=right->next;
            
            }
            temp=temp->next;

        }

        if(left) temp->next=left;
        if(right) temp->next=right;

        return merged->next;

    }
};