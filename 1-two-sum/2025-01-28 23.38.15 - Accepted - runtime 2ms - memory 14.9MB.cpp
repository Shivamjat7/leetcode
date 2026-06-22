class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map <int,int> mpp;
        for(int i=0;i<n;i++){
            int a=nums[i];
            int b=target-nums[i];
            if(mpp.find(b)!=mpp.end()){
                return {i,mpp[b]};
            }
            mpp[a]=i;
        }
        return {};
}
};