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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        ListNode * temp = dummy;
        ListNode* curr = head;
    
        while(curr){
            if(curr->next && curr->val==curr->next->val ){
                int duplicateVal=curr->val;
                while(curr && curr->val == duplicateVal) curr=curr->next;
                temp->next = curr;
            }
            else{
                temp->next =curr;
                temp= temp->next;
                curr = curr->next;
            }
            
        }
        return dummy->next;
    }
};