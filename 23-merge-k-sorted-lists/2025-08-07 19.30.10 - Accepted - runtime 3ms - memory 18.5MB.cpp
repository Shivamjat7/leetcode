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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode*  dummy = new ListNode(-1);
        ListNode* temp = dummy;
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<>> pq;
        for(int i =0;i<lists.size();i++){
           if(lists[i]) pq.emplace(lists[i]->val,lists[i]);
        }
        while(!pq.empty()){
            auto [val,node] = pq.top();
            pq.pop();
            temp->next = node;
            temp=temp->next;
            if(node->next){
                pq.emplace(node->next->val,node->next);
            }
        }
        return dummy->next;
        
    }
};