class Solution {
public:
    int gcdOfOddEvenSums(int n) {
       int cnt =1;
       int sumOdd=0;
       int sumEven =0;
       while(n--){
        sumOdd+=cnt++;
        sumEven+=cnt++;
       } 
       return gcd(sumOdd,sumEven);
    }
};