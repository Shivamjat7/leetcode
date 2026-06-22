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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1,st2;
        ListNode* temp = l1;
        while(temp){
            st1.push(temp->val);
            temp=temp->next;
        }
        temp = l2;
        while(temp){
            st2.push(temp->val);
            temp=temp->next;
        }
        ListNode* head = nullptr;
        int carry =0;
        while(!st1.empty() && !st2.empty()){
            int sum = st1.top()+st2.top()+carry;
            st1.pop();
            st2.pop();
            ListNode* node = new ListNode(sum%10);
            node->next=head;
            head=node;
            carry =sum/10;
            
        }
        while(!st1.empty() ){
            int sum = st1.top()+carry;
            st1.pop();
            ListNode* node = new ListNode(sum%10);
            node->next=head;
            head=node;
            carry =sum/10;
            
        }
        while(!st2.empty() ){
            int sum = st2.top()+carry;
            st2.pop();
            ListNode* node = new ListNode(sum%10);
            node->next=head;
            head=node;
            carry =sum/10;
        }
        if(carry){
            ListNode* node = new ListNode(carry);
            node->next=head;
            head=node;
        }
        return head;
    }
};