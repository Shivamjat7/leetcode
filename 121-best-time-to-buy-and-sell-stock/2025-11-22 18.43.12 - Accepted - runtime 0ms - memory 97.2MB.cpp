class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxPro =0;
        for(int price: prices){
            minPrice=min(price,minPrice);
            maxPro = max(maxPro,price-minPrice);
        }
        return maxPro;
    }
};