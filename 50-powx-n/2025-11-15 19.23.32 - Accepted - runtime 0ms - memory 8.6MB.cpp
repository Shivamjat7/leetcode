class Solution {
public:
    double myPow(double x, int n) {
        long long exp =n;
        if(exp<0){
            x = 1/x;
            exp =-exp;
        }
        double ans=1;
        while(exp>0){
            if(exp&1){
                ans *=x;
            }
            exp=exp>>1;
            x=x*x;
        }
        return ans;
    }
};