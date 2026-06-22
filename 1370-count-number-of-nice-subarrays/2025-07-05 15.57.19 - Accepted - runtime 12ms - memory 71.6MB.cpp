class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int count =0;
        int ans=0;
        int left=0;
        for( int right = 0;right<nums.size();right++){
            if(nums[right]%2==1)count++;
            while(count>k){
                if(nums[left]%2==1) count--;
                left++;
            }
            if(count ==k){
                int temp=left;
                while(temp<right && nums[temp]%2==0) temp++;
                ans+=temp-left+1;
            }
        }
        return ans;
    }
};