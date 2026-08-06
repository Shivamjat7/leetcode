class Solution {
public:
    long product(int num){
        long ans =1;
        while(num>0){
            int d = num%10;
            ans*=d;
            num=num/10;
        }
        return ans;
    }
    int smallestNumber(int n, int t) {
       
        for(int num =n;num<=1000;num++){
            if(product(num)%t==0)return num;
        }
        return -1;
        
    }
};