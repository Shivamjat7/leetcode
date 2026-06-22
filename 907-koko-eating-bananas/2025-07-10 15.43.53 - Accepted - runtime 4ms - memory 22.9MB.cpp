class Solution {
public:
    long long hoursToEat(vector<int> & piles,int hour){
        long long total=0;
        for(auto bananas:piles){
            total += (bananas +hour-1)/hour;
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int high=0;
        for(auto it: piles){
            if(high<it) high=it;
        }
        int low =1;
        int ans=high;
        while(low<=high){
            int mid = low +(high-low)/2;
            if(hoursToEat(piles,mid)<=h){
                ans=mid;
                high=mid-1;
            }else low =mid+1;

        }
        return ans;
        
    }
};