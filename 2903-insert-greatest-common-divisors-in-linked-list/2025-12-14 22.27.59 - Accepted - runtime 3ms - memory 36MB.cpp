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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head||!head->next)return head;
        ListNode* lastNode = head;
        ListNode* curr = head->next;
        while( curr){
            int g = gcd(lastNode->val,curr->val);
            ListNode* newNode= new ListNode(g);
            newNode->next = curr;
            lastNode->next= newNode;
            lastNode=curr;
            curr=curr->next;
        }
        return head;
    }
};