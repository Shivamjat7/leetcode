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
    ListNode* partition(ListNode* head, int x) {
        if (!head ) return head;
        ListNode* curr = head;
        ListNode* dummy1= new ListNode(-1);
        ListNode* dummy2= new ListNode(-1);
        ListNode* greater= dummy1;
        ListNode* smaller = dummy2;
    
        while( curr){
            if ( curr->val < x){
                smaller ->next =curr;
                smaller = smaller->next;
                
            }else{
                greater->next = curr;
                greater = greater->next;
                
            }
            curr = curr->next;
        }

            greater->next = nullptr;
            smaller->next = dummy1->next;
            
        
        return dummy2->next;


    }
};