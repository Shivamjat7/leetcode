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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr) return head;
        int len=1;
        ListNode* tail =head;
        while(tail && tail->next){
            tail=tail->next;
            len++;
        }
        if(tail !=head) tail->next=head;
        ListNode* temp =head;
        int cnt =1;
        while( cnt != len-k%len){
            temp=temp->next;
            cnt++;
        }
       if(temp) head=temp->next;
        if(temp)temp->next =nullptr;
        return head;
        
    }
};