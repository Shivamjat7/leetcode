class Solution {
public:
    int reverseBits(int n) {
        int ans =0;
        int cnt =32;
        while(cnt--){
           ans= ans<<1;
            if(n&1){
                ans|=1;
            }
            n = n>>1;
            
        }
        return ans;
    }
};