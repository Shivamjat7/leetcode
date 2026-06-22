class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1;
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        int sign =1;
        long ans=0;
        if(dividend >0 && divisor<0 || dividend<0 && divisor>0) sign =-1;
        long long n = llabs((long long)dividend);
        long long d = llabs((long long )divisor);
        while(n>=d){
            int cnt =0;
            while(n>=(d<<cnt)){
                cnt++;
            }
            cnt--;
            ans+=(1<<cnt);
            n=n-(d<<cnt);
        }
        if(ans>INT_MAX)return INT_MAX;
        if(ans<INT_MIN)return INT_MIN;
        return sign*ans;
    }
};