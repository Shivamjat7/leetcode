class Solution {
public:
    long long sumAndMultiply(int n) {
        string num =to_string(n);
        long long x =0;
        long long sum=0;
        for(char ch:num){
            if(ch=='0')continue;
            int val = ch-'0';
            x=x*10+val;
            sum+=val;
        }
        return x*sum;
    }
};