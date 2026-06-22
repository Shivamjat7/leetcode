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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left == right) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;
        int i=1;
        while(i<left){
            prev = prev->next;
            i++;
        }
        ListNode* curr = prev->next;
        ListNode* nextNode = nullptr;
        for(int i =0;i<right-left;++i){
                nextNode = curr->next;
                curr->next = nextNode->next;
                nextNode->next = prev->next;
                prev->next =nextNode;

        }
        return dummy->next;

        
    }
};