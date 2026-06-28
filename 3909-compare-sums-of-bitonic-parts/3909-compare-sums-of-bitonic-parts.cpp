class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        long long sumLeft=0,sumRight=0;
        int l=0,r=nums.size()-1;
        while(l<r){
            if(nums[l]<nums[l+1]){
                sumLeft+=nums[l];
                l++;
            }
            if(nums[r]<nums[r-1]){
                sumRight+=nums[r];
                r--;
            }
        }
        if(sumLeft>sumRight) return 0;
        if(sumLeft<sumRight) return 1;
        return -1;
        
    }
};