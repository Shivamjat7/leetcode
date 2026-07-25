class Solution {
public:
    int maxProduct(int n) {
        int d1=0;
        int d2=0;
        while(n>0){
            int d = n%10;
            n=n/10;
            if(d>d1){
                d2=d1;
                d1=d;
            }
            else if(d>d2)d2=d;
        }
        return d1*d2;
    }
};