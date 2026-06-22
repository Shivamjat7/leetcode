class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n =prices.size();
        vector<vector<int>> after(2,vector<int>(3,0));
        vector<vector<int>> curr(2,vector<int>(3,0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                for(int cap=1;cap<=2;cap++){
                    if(j){
                        curr[j][cap]= max(-prices[i]+after[0][cap],after[1][cap]);
                    }else curr[j][cap]= max(prices[i]+after[1][cap-1],after[0][cap]);
                }
               
            }
            after=curr;
        }
        return curr[1][2];
    }
};