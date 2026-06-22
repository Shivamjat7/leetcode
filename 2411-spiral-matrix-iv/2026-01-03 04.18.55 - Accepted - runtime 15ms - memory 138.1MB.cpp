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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
          vector<vector<int>> matrix(m,vector<int>(n));
        int p=0, q=0, r=n-1,s=m-1;
        
    while(p<=r && q<=s) {   
        for(int i=p;i<=r;i++){
            matrix[q][i]=head?head->val:-1;
            if(head) head=head->next;
        }
        q++;
        for(int i=q;i<=s;i++){
            matrix[i][r]=head?head->val:-1;
            if(head) head=head->next;
        }
        r--;
        if(q<=s)
        for(int i=r;i>=p;i--){
            matrix[s][i]=head?head->val:-1;
            if(head) head=head->next;
        }
        s--;
        if(p<=r)
        for(int i=s;i>=q;i--){
            matrix[i][p]=head?head->val:-1;
            if(head) head=head->next;
            
        }
        p++;}
    
        return matrix;
    }
};