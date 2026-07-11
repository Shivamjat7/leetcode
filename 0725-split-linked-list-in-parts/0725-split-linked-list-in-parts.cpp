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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len=0;
        ListNode* temp =head;
        while(temp){temp=temp->next;len++ ;};
        temp =head;
        vector<ListNode*>ans;
        while(temp && k>0){
            int cnt =0;
            ans.push_back(temp);
            int cut = ceil(double(len)/k);
            cnt++;
            len=len-cut;
            k--;
            while(cnt<cut && temp){
                temp=temp->next;
                cnt++;
            }
            
            if(temp){
            ListNode* t =temp->next;
            temp->next = nullptr;
            temp =t;}

        }
        while(k>0){
            ans.push_back(nullptr);
            k--;
        }
        return ans;
    }
};