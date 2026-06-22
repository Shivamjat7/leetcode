class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        long product=1;
        int cnt=0;
        int left=0;
        for(int right=0;right<nums.size();right++){
            product=product*nums[right];
            while(product>=k){
                product/=nums[left++];
            }
            cnt+=(right-left+1);
        }
    
        return cnt;
        
    }
};