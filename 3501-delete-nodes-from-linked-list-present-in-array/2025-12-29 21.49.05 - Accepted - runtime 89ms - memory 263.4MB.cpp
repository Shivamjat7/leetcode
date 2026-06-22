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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if(!head) return head;
        unordered_set<int>st(nums.begin(),nums.end());
        while(head && st.count(head->val)){
            head=head->next;
            
        }
        if(!head)return nullptr;
        ListNode* prev = head;
        ListNode* curr = head->next;
        while(curr){
            if(st.count(curr->val)){
                prev->next=curr->next;
                curr=curr->next;
            }else{
                prev=curr;
                curr=curr->next;
            }
        }
        return head;
    }
};