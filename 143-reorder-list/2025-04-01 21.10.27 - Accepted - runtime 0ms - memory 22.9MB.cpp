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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode* fast= head ->next;
        ListNode* slow = head;
        while(fast && fast->next && fast->next->next){
            fast = fast->next->next;
            slow=slow->next;
        } 
        
        ListNode* secondHead=reverse(slow->next);
        slow->next=nullptr;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        ListNode* temp1= head;
        ListNode* temp2 = secondHead;
        int i =0;
        while(temp && temp1 && temp2){
            if(i%2==0){
                temp->next=temp1;
                temp1=temp1->next;
                temp=temp->next;

            }else{
                temp->next=temp2;
                temp2= temp2->next;
                temp=temp->next;
            }
            i++;
        }
        while(temp && temp1){
            temp->next = temp1;
            temp1= temp1->next;
            temp= temp->next;
        }
        while(temp &&  temp2){
            temp->next= temp2;
            temp2= temp2->next;
            temp= temp->next;
        }
        
    }
    ListNode* reverse(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* curr= head , *prev = nullptr;
        while( curr ){
            ListNode* temp = curr->next;
            curr->next=prev;
            prev = curr;
            curr= temp;
        }
        return prev;
    
    }


};