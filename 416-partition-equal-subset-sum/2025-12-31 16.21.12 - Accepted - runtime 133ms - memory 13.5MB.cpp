class Solution {
public:
  
    bool canPartition(vector<int>& nums) {
        int sum =accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0)return false;
        int target=sum/2;
        int n=nums.size();
        vector<bool>prev(target+1,false),curr(target+1,false);
         prev[0]=curr[0]=true;
       if(target>=nums[0]) prev[nums[0]]=true;
        for(int i=1;i<n;i++){
            for(int t=1;t<=target;t++){
                bool notPick = prev[t];
                bool pick = false;
                if(t>=nums[i]) pick = prev[t-nums[i]];
                curr[t]=notPick||pick;
            }
            prev=curr;
        }
        return curr[target];
        
    }
};