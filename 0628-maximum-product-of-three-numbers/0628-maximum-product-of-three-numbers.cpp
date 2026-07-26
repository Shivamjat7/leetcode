class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int mx1=INT_MIN,mx2=INT_MIN,mx3=INT_MIN;
        int mn1=INT_MAX,mn2=INT_MAX;
        for(int num:nums){
            if(num>=mx1){
                mx3=mx2;
                mx2=mx1;
                mx1=num;
            }else if( num>=mx2){
                mx3=mx2;
                mx2=num;
            }else if(num>=mx3) mx3=num;
             if(num<=mn1){
                mn2=mn1;
                mn1=num;
            }else if( num<mn2){
                mn2=num;
            }
        }
        return max(mx1*mx2*mx3,mn1*mn2*mx1);
    }
};