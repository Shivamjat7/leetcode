class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int x =0;
        for(int num:nums) x^=num;
        x=x^k;
        int cnt =0;
        while(x>0){
            if(x&1)cnt++;
            x=x>>1;
        }
        return cnt;
    }
};