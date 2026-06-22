class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mxProduct=nums[0];
        int mnProduct =nums[0] ;
        int ans =nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0) swap(mxProduct,mnProduct);
            
            mxProduct = max(mxProduct*nums[i],nums[i]);
            mnProduct = min(mnProduct*nums[i],nums[i]);
            ans= max(ans,mxProduct);
        }
        return ans ;
    }
};