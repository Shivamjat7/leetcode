class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            int val=nums[i];
            int j=0;
            while(val&1){
                j++;
                val=val>>1;
            }
            if(j>0){
                j--;
            ans[i]=nums[i]^(1<<j);
            }
            
        }
        return ans;
    }
    
};