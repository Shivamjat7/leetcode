class Solution {
public:
    int countDigitOne(int n) {
        long long ans;
        for(long long factor =1;factor<=n;factor*=10){
            long long high  = (n/(factor*10));
            long long curr = ( n/factor)%10;
            long long lower = (n%factor);
            if(curr>1){
                ans+=( high+1)*factor;
            }
            else if( curr ==1){
                ans += high*factor+lower+1;
            }else if ( curr ==0){
                ans += high*factor;
            }

        }
        return ans;
    }
};