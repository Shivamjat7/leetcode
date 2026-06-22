class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high =0;
        for(auto weight:weights)high+=weight;
        int minCapacity =high;
        while(low<=high){
            int mid = low +(high-low)/2;
            if(canShip(weights,days,mid)){
                minCapacity =mid;
                high  =mid-1;
            }else low = mid+1;
        }
      return minCapacity;  
    }
    bool canShip(vector<int>& weights,int days,int capacity){
        int cntDays =1;
        int load=0;
        for(int i =0;i<weights.size();i++){
            if(load+weights[i]>capacity){
                load =0;
                cntDays++;
            }
            load +=weights[i];
            if(cntDays>days)return false;
        }
        return true;
    }
};