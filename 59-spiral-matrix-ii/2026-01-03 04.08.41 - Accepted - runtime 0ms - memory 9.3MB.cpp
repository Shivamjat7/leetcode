class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
    
        vector<vector<int>> matrix(n,vector<int>(n));
        int p=0, q=0, r=n-1,s=n-1;
        int num=1;
    while(p<=r && q<=s) {   
        for(int i=p;i<=r;i++){
            matrix[q][i]=num;
            num++;
        }
        q++;
        for(int i=q;i<=s;i++){
            matrix[i][r]=num++;
            
        }
        r--;
        if(q<=s)
        for(int i=r;i>=p;i--){
            matrix[s][i]=num++;
        }
        s--;
        if(p<=r)
        for(int i=s;i>=q;i--){
            matrix[i][p]=num++;
            
        }
        p++;}
    
        return matrix;

        
    
            
    }
};