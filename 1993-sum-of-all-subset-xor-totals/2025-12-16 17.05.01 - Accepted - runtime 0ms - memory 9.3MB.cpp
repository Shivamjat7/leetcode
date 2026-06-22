class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        
        int  n =nums.size();
        int ans =0;
        for(int mask=0;mask<(1<<n);mask++){
            int x =0;
            for(int i =0;i<n;i++){
                if(mask&(1<<i)){
                    x=x^nums[i];
                }
            }
            ans+=x;
        }
        return ans;
    }
};