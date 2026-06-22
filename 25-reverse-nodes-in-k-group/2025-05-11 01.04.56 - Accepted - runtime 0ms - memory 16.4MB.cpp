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
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head||!head->next) return head;
        ListNode* node=head;
        for( int i=0;i<k;++i){
            if(!node) return head;
            node=node->next;
        }
        ListNode* temp=nullptr;
        ListNode* curr=head;
        ListNode* prev=nullptr;
        for(int i=0;i<k;++i){
            temp= curr->next;
            curr->next= prev;
            prev=curr;
            curr=temp;
        }
        head->next=reverseKGroup(curr,k);
        return prev;
    }
};