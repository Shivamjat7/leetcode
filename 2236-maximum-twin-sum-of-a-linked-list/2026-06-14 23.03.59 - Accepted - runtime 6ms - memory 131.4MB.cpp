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
    int pairSum(ListNode* head) {
        ListNode* fast =head;
        ListNode* slow = head;
        stack<int> st ;
        while(fast){
            st.push(slow->val);
            fast =fast->next->next;
            slow =slow->next;
        }
        ListNode* temp = slow;
        int ans =INT_MIN;
        while(temp && !st.empty()){
            ans = max(ans,st.top()+temp->val);
            temp=temp->next;
            st.pop();
        }
        return ans;
    }
};