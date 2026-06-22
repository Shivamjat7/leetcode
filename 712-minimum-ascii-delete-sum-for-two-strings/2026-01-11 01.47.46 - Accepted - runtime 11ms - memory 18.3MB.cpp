class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j]=s1[i-1]+dp[i-1][j-1];
                else dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int sum =0;
        int i=n,j=m;
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                i--;
                j--;
            }else if( dp[i][j-1]>=dp[i-1][j]){
                sum+=s2[j-1];
                j--;
            }else {
                sum+=s1[i-1];
                i--;
            }
        }
        while(i>0){
            sum+=s1[i-1];
            i--;
        }
        while(j>0){
            sum+=s2[j-1];
            j--;
        }
        return sum;
    }
};