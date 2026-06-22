class Solution {
public:
    bool isPerfectSquare(int num) {
        
        int low = 1,high = num;
        while(low<=high){
            int mid = low+(high-low)/2;
            long long  sq = (1LL)*mid*mid;
            if( sq == num)return true;
            else if ( sq >num) high=mid-1;
            else low = mid+1;
        }
        return false;
    }
};