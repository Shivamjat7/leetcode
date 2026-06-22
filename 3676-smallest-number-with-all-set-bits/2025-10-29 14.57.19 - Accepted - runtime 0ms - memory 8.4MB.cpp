class Solution {
public:
    int smallestNumber(int n) {
    long long x;
        int m=0;
        while(true){
            x=pow(2,m);
            if(x>n) break;
            m++;
        }
        return x-1;
    }
};