class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>prev(m,0),curr(m,0);
        int mx =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0){
                    curr[j]=matrix[i][j]-'0';
                }
                else if( matrix[i][j]=='0'){
                    curr[j]=0;
                }else {
                   int mn=min({prev[j-1],prev[j],curr[j-1]});
                    curr[j] = max(mn+1,1);
                }
                mx = max(mx,curr[j]*curr[j]);
            }
            prev=curr;
        }
        return mx;

    }
};