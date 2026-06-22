class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int i=0;
        int count =0;
        for( int j=0;j<nums.size();j++){
            if(nums[j] != val){
                count++;
                if(j != i){
                int temp = nums[j];
                nums[j]=nums[i];
                nums[i]= temp;
                i++;}else{
                    i++;
                }

            }
        }
        return count;
    }
};