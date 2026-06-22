class Solution {
public:
    int totalMoney(int n) {
        int money =0;
        int day =0;
        int monday =0;
        int prev =0;
        while(day<n){
            if(day%7==0){
                monday++;
                prev=monday;
            }
            money+=prev;
            prev++;
            day++;
        }

return money;
    }
};