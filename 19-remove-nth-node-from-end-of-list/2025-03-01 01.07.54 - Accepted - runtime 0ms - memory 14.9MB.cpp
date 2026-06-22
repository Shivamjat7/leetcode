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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr || head->next== nullptr) return nullptr;
        ListNode* fast=head, *slow=head;

        while(n){
            fast=fast->next;
            n--;
        }
        if(fast== nullptr){
            ListNode* temp= head;
            head=head->next;
            delete temp;
            return head;
        }
        while(fast !=nullptr && fast->next != nullptr){
            fast=fast->next;
            slow=slow->next;

        }
        if(slow != nullptr && slow->next != nullptr)
        slow->next=slow->next->next;
        if(slow->next== nullptr){
            slow=nullptr;
        }
        return head;


        
    }
};