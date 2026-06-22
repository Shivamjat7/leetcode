class Solution {
public:
 
  
    int minimumTotal(vector<vector<int>>& triangle) {
        int n =triangle.size();
        vector<int>prev(n,1e9);
        for(int j =0;j<n;j++) prev[j]=triangle[n-1][j];
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                prev[j]=triangle[i][j]+min(prev[j],prev[j+1]);
            }
        }
        return prev[0]; 
        
    }
};