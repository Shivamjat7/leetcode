class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int cnt =0;
        for(int cost :costs){
            if(coins-cost>=0){
                cnt++;
                coins=coins -cost;
            }
        }
       return  cnt;
    }
};