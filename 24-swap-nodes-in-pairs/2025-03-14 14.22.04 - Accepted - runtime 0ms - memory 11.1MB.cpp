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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* curr = head;
        head = head->next;
        ListNode* dummy = new ListNode( -1);
        ListNode* prev = dummy;
        dummy->next =head;


        while (curr && curr->next) {
            ListNode* temp1 = curr->next->next;
            ListNode* temp2 = curr->next;

            temp2->next = curr;
            curr->next =temp1;
            prev->next = temp2;

            prev = curr;
            curr = temp1;
        }

        return head;
    }
};