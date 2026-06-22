class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n =prices.size();
        vector<int>curr(2,0),after(2,0);
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j){
                    curr[j]=max( -prices[i]+after[0]-fee,after[1]);
                }else{
                    curr[j]=max(prices[i]+after[1],after[0]);
                }
            }
            after=curr;
        }
        return curr[1];

    }
};