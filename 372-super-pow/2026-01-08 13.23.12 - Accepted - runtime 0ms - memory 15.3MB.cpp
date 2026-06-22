class Solution {
public:
    int MOD= 1337;
    int pow(int x, int n){
        int res =1;
        x%=MOD;
        while(n>0){
            if(n&1){
                res = (res*x)%MOD;
            }
            x=(x*x)%MOD;
            n=n>>1;
        }
        return res;
    }
    int superPow(int a, vector<int>& b) {
        int res =1;
        for(int x:b){
            res= (pow(res,10)*pow(a,x))%MOD;
        }
        return res;
    }
};