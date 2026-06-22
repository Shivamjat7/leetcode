class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans=left & right;
        int cnt =0;
        while(left<right){

            ans = ans & ++left & --right;
            if((ans&1)==0){
                ans = ans>>1;
               left = left>>1;
                right=right>>1;
                cnt ++;
            }
            
            
        }
        ans= ans<<cnt;
        return  (ans<=INT_MAX)?ans:0;
    }
};