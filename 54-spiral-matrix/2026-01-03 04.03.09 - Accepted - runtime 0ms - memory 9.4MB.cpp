class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int p=0, q=0, r=m-1,s=n-1;
        vector<int> ans;
    while(p<=r && q<=s) {   
        for(int i=p;i<=r;i++){
            ans.push_back(matrix[q][i]);
        }
        q++;
        for(int i=q;i<=s;i++){
            ans.push_back(matrix[i][r]);
        }
        r--;
        if(q<=s)
        for(int i=r;i>=p;i--){
            ans.push_back(matrix[s][i]);
        }
        s--;
        if(p<=r)
        for(int i=s;i>=q;i--){
            ans.push_back(matrix[i][p]);
            
        }
        p++;}
    
        return ans;

        
    }
};