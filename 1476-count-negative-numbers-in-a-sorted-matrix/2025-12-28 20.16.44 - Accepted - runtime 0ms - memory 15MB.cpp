class Solution {
public:
    int count(vector<int>& arr){
        int low =0;
        int high= arr.size()-1;
        while(high>=low){
            int mid= low+(high-low)/2;
            if(arr[mid]<0)high=mid-1;
            else low= mid+1;
        }
        return arr.size()-low;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int cnt=0;
        for(auto arr:grid){
            cnt+=count(arr);
        }
        return cnt;
    }
};