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
    ListNode* reverse(ListNode* head){
        ListNode* curr= head;
        ListNode* prev= nullptr;
        ListNode* temp= nullptr;
        while( curr != nullptr){
            temp= curr->next;
            curr->next= prev;
            prev= curr;
            curr= temp;
            
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if( head == nullptr || head->next == nullptr) return true;
       
        ListNode* slow= head , *fast= head;
       
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* second= reverse(slow);
        ListNode* temp1=head;
        ListNode* temp2 =second;
        while( temp2 != nullptr){
            if(temp1->val!=temp2->val){
                return false;
            }
            temp1=temp1->next;
            temp2=temp2->next;

        }
        reverse(second);
        return true;


        
    }

    
};