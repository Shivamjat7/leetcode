class Solution {
public:
    int hammingDistance(int x, int y) {
        int cnt =0;
        x = x^y;
        while(x){
            if( x&1)cnt++;
            x=x>>1;
        }
        return cnt;
    }
};