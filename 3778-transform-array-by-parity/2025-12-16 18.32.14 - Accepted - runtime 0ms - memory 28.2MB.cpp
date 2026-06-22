class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int one =0;
        int zero =0;
      for(int i =0;i<nums.size();i++){
        if(nums[i]%2)one++;
        else zero++;
      } 
      for(int i =0;i<nums.size();i++) {
        if(zero>0){
            nums[i]=0;
            zero--;
        }
        else {
            nums[i]=1;
            one--;
        }
      }
      return nums;
    }
};