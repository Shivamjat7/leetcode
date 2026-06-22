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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        ListNode* temp = dummy;
        ListNode* curr=head;
        while(curr ){
            if(curr->val){
            temp->val+=curr->val;
            }else if(!curr->next) temp->next = nullptr;
            else {
                temp->next=curr;
                temp=curr;
            
            }
            curr=curr->next;
        }
        return dummy->next;;
    }
};