class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long x =0;
        for(int num:nums) x=x^num;
        
        long long diff= x&(-x);
        int a =0,b=0;
        for(int num: nums){
            if(num&diff){
                a=a^num;
            }else{
                b=b^num;
            }
        }
        return {a,b};
        
        
        
    }
};