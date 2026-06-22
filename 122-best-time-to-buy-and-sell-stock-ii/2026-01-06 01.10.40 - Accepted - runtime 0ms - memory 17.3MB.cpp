class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> curr(2,0),prev(2,0);
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                if(j){
                    curr[j]= max(-prices[i]+ prev[0],prev[1]);
                }else{
                    curr[j]=max(prices[i]+prev[1],prev[0]);
                }
            }
            prev=curr;
        }
        return curr[1];
    }
};