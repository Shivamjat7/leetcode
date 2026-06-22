class Solution {
public:
    int reverse(int x) {
        long long int res=0,rem=0;
        while(x!=0){
             rem=x%10;
            x=x/10;
            res=res*10+rem;

        }
        if( abs(res)>INT_MAX) return 0;
        return res;
        
    }
};