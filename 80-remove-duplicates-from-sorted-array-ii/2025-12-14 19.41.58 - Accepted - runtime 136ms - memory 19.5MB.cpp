class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n<3)return n;
        int right =n;
        int k = 2;
        int i =2;
        while(i<right){
            if(nums[i]==nums[i-1] && nums[i-1]==nums[i-2] ){
                right--;
                for(int k =i;k<right;k++){
                    nums[k]=nums[k+1];
                }
                
            }else {
                i++;
                k++;
            }
            
        }
        return k;
    }
};