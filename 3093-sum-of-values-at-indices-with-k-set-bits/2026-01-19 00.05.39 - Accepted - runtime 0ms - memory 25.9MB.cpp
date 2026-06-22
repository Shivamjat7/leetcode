class Solution {
public:
    int countBit(int n){
        int cnt =0;
        while(n){
            n= n&(n-1);
            cnt++;
        }
        return cnt;
    }
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum =0;
        for(int i=0;i<nums.size();i++){
            if(countBit(i)==k){
                sum+=nums[i];
            }
        }
        return sum;
    }
};