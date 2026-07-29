class Solution {
public:
    bool can(int i,int k,vector<int>&stones,vector<vector<int>>&dp){
        if(i==stones.size()-1)return true;
        if(dp[i][k]!=-1)return dp[i][k];
        bool ans = false;
        for(int j=k-1;j<=k+1;j++){
            if(j<=0)continue;
            for(int next =i+1;next<stones.size();next++){
                int dist =stones[next]-stones[i];
                if(dist ==j){
                    ans =ans ||can(next,j,stones,dp);
                }
            }
        }
        return dp[i][k]=ans;
        
        
        return ans;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return can(0,0,stones,dp);
        
    }
};