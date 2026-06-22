class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0, high =nums.size(), result = high; 
        
        while(high>low){
            int mid=low+(high-low)/2;
            if(nums[mid]>= target) {
                result = mid;
                high = mid;

            }else{
                low = mid+1;
            }

        }
        return result;
        
    }
};