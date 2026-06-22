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
    pair<ListNode*,int> f(ListNode* head){
        if(!head)return {head,0};
      auto[node,carry]= f(head->next);
      int d = (2*head->val+carry);
      carry = d/10;
      head->val= d%10;
      return {head,carry}; 
    }
public:
    ListNode* doubleIt(ListNode* head) {
        auto [node,carry]=f(head);
        if(carry){
            ListNode* one = new ListNode(1);
            one->next=node;
            return one;
        }
        return node;
    }
};