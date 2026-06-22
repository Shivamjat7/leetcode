class Solution {
public:
    int reverse(int n){
        int x=0;
        while(n>0){
            int d = n%10;
            n=n/10;
            x = x*10+d;
        }
        return x;
    }
    int mirrorDistance(int n) {
        return abs(n-reverse(n));
    }
};