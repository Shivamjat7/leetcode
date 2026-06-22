class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        bool inc1 =nums[1]>nums[0];
        bool dec1 = false;
        bool dec2 = false;
        bool inc2=false;

        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1])return false;
            if(nums[i]>nums[i-1]){
                if( inc1 && dec1) inc2 =true;
            }else {
                if(inc1)dec1=true;
                if(inc1 && inc2)dec2=true;
            }
        }
        return inc1&&inc2&&dec1 && !dec2;
    }
};