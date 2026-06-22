class Solution {
public:
    bool canJump(vector<int>& nums) {
        int currentMax =0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(i>currentMax)break;
            currentMax = max(currentMax ,nums[i]+i);
        }
        return currentMax>=n-1;
    }
};