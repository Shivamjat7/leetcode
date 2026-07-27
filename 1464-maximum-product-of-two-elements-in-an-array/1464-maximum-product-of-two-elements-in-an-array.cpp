class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx1=INT_MIN,mx2=INT_MIN;
        int mn1=INT_MAX,mn2=INT_MAX;
        for(int val :nums){
            if(val>=mx1){
                mx2=mx1;
                mx1=val;
            }else if( val>=mx2)mx2=val;

            if(val<=mn1){
                mn2=mn1;
                mn1=val;
            }else if( val<=mn2)mn2 =val;
        }
        int ans1 = (mx1-1)*(mx2-1);
        int ans2 = (mn1-1)*(mn2-1);
        return max(ans1,ans2);
    }
};