class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int minDiff =INT_MAX;
        int ans=0;
        for(int i =0;i<nums.size();i++){
            int j= i+1, k = nums.size()-1;
            while( j<k){
                int sum = nums[i]+nums[j]+nums[k];
                int diff = abs(target-sum);
                if( diff<minDiff){
                    minDiff=diff;
                    ans =sum;
                }
                if( sum==target)return sum;
                else if(sum>target)k--;
                else j++;
                

                
            }
        }
        return ans;
    }
};