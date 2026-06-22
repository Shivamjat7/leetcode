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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp =head;
        ListNode* prev=nullptr;
        while( temp!= nullptr ){
            if( temp->val == val ){
                if(temp == head){
                    head=head->next;
                    delete temp;
                    temp=head;
                    
                }else{
                  if(prev) prev->next= temp->next;
            
                    ListNode* toDelete =temp;
                    temp=temp->next;
                    delete toDelete;

                }
            }else{
                prev=temp;
                temp=temp->next;
            }
        }
    return head;
        
    }
};