class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
    map<int ,int> mpp;
    for(int i=0;i<n;i++){
        mpp[nums[i]]++;
    }
    int most=-1,freq=0;
    for( auto [key,value]:mpp){
        if(value>freq){
            freq=value;
            most=key;
        }


    }
    return most;
    }
};