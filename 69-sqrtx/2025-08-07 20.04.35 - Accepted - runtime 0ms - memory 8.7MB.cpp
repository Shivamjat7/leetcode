class Solution {
public:
    int mySqrt(int n) {
        int low =0,high =n;
        int ans =0;
        while(low<=high){
            long long mid = low +(high -low)/2;
            if( mid*mid <=n){
                ans = mid;
                low = mid+1;
            }else high = mid-1;
        }
        return ans;
    }
};